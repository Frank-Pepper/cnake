#include "Frame.h"
#include <memory>



GUIObserver::GUIObserver(const GamePtr &game, Frame *frame) : Observer(game), frame(frame) {

}

void GUIObserver::report()
{
    frame->prepare(getGame());
}

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
				EVT_CLOSE(Frame::OnClose)
                EVT_RIGHT_DOWN(Frame::play)
                EVT_LEFT_DOWN(Frame::play)
                EVT_TIMER(wxID_ANY, Frame::OnTimer)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    CreateStatusBar();
    SetBackgroundColour(wxColour(*wxBLACK));
    timer = new wxTimer(this, wxID_ANY);
    timer->Start(650);
    SetClientSize(1100, 1100);
    Bind(wxEVT_PAINT, &Frame::OnPaint, this);
    Bind(wxEVT_THREAD, (wxObjectEventFunction) &Frame::OnThreadUpdate, this);
}

void Frame::OnPaint(wxPaintEvent &event)
{
    event.Skip();
    wxSize s = GetClientSize();
    int dx = (double(s.x) / width);
    int dy = (double(s.y) / height);
    int r = 30;
    std::vector<SegmentPtr> snake = game->getSnake()->getSegments();
    wxPaintDC dc(this);
    SetStatusText("Snake \tScore: " + std::to_string(game->getScoreManager()->calculateScore()) + "\tHighscore: " +
                          std::to_string(game->getScoreManager()->getHighScore()));
    dc.SetBrush(*wxRED_BRUSH);
    dc.DrawCircle((fruit.x-1)*dx + dx / 2, s.y-fruit.y*dy + dy / 2, r);
    auto it = seg.begin();
    dc.SetBrush(*wxBLUE_BRUSH);
    wxPoint p = *it;
    dc.DrawCircle((p.x-1) * dx + dx / 2, s.y-p.y * dy + dy / 2, r);
    dc.SetBrush(*wxGREEN_BRUSH);
    for (it++; it != seg.end(); it++) {
        wxPoint p = *it;
        dc.DrawCircle((p.x-1) * dx + dx / 2, s.y-p.y * dy + dy / 2, r);
    }

    dc.SetPen(*wxCYAN_PEN);
    dc.DrawLine(10, 10, 10, s.y-10);
    dc.DrawLine(10, 10, s.x-10, 10);
    dc.DrawLine(s.x-10, s.y-10, s.x-10, 10);
    dc.DrawLine(10, s.y-10, s.x-10, s.y-10);
}

void Frame::OnClose(wxCloseEvent &event)
{
    delete timer;
	stop();
	Destroy();
}

void Frame::stop() {
	std::lock_guard<std::mutex> guard(mx);
}

void Frame::prepare(GamePtr game) {
    std::lock_guard<std::mutex> guard(mx);
    width = game->getXSize();
    height = game->getYSize();
    seg.clear();
    for( auto segment : game->getSnake()->getSegments() ){
        wxPoint point(segment->getLocation().first, segment->getLocation().second);
        seg.push_back(point);
    }
    wxPoint point(game->getFruit()->getLocation().first, game->getFruit()->getLocation().second);
    fruit = point;
    wxQueueEvent(GetEventHandler(), new wxThreadEvent());
}

void Frame::run()
{
    srand(time(0));
    try{
        game = std::make_shared<Game>(11, 11);
        observer = std::make_shared<GUIObserver>(game, this);
        observer->report();
    } catch(GameException e) {
        std::cout << e.what() << "\n";
        Close();
    }
}

void Frame::OnThreadUpdate(wxThreadEvent &evt) {
	Refresh();
}

const GamePtr &Frame::getGame() const {
    return game;
}

void Frame::play(wxMouseEvent &event) {
    timer->Stop();
    SnakePtr snake = game->getSnake();
    direction dir = snake->getHead()->getD();
    if(event.RightDown()){
        dir = static_cast<direction>((dir + 1)%5);
        if( dir == 0){
            dir = down;
        }
    } else{
        dir = static_cast<direction>((dir - 1)%5);
        if( dir == 0){
            dir = right;
        }
    }
    checkGame(dir);
}

void Frame::OnTimer(wxTimerEvent &event) {
    timer->Stop();
    checkGame(game->getSnake()->getHead()->getD());
}

void Frame::checkGame(direction dir) {
    game->getSnake()->moveAll(dir);
    game->increaseTime();
    observer->report();
    if(game->checkCollision() || game->checkWin())
    {
        game->getScoreManager()->writeScore();
        Close();
    } else
    {
        timer->Start();
    }
}
