#ifndef SNAKEGAME_FRAME_H
#define SNAKEGAME_FRAME_H


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Observer.h"
#include <wx/event.h>
#include <mutex>
#include <list>
#include <thread>


class Frame;

class GUIObserver : public Observer
{
private:
	Frame* frame;
public:
    GUIObserver(const GamePtr &game, Frame *frame);
    void report() override;
};

class Frame : public wxFrame
{
public:
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
    const GamePtr &getGame() const;
    void checkGame(direction dir);
    friend class GUIObserver;
    void run();

private:
	std::mutex mx;
	int width = 1;
	int height = 1;
    wxTimer *timer;
    GamePtr game;
    std::list<wxPoint> seg;
    wxPoint fruit;
    ObserverPtr observer;
private:

    void OnPaint(wxPaintEvent &event);
    void OnClose(wxCloseEvent &event);
    void stop();
    void prepare(GamePtr game);
    void OnThreadUpdate(wxThreadEvent &evt);
    void play(wxMouseEvent &event);
    void OnTimer(wxTimerEvent &event);
    wxDECLARE_EVENT_TABLE();

};


#endif //SNAKEGAME_FRAME_H
