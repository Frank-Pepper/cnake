
#include <iostream>
#include "Game.h"
#include "Snake.h"
#include "CLIObserver.h"
#include <wx/wxprec.h>

using namespace std;

/* // Delete the "/*" in this line to play using command line observer (if you want to go back just copy it back into place)

int main()
{
	srand(time(0));
    try{
        GamePtr gra = make_shared<Game>(11, 11);
        std::shared_ptr<CLIObserver> zbysiu = make_shared<CLIObserver>(gra);
        zbysiu->play();
        std::cout << "witaj swiecie" << "\n";
        gra->getScoreManager()->writeScore();
    } catch(GameException e) {
        cout << e.what() << "\n";
    }

    return 0;
}

*/ // Delete the "*/" in this line to play using command line observer (if you want to go back just copy it back into place)

   // Add a "/*" in this line to play using command line observer (if you want to go back just copy it back into place)


#include "Frame.h"



class Application: public wxApp
{
private:
	thread *simulation_thread;

public:
	virtual bool OnInit();
	virtual int OnExit();
};

wxIMPLEMENT_APP(Application);

bool Application::OnInit()
{
	auto *frame = new Frame("Snake", wxPoint(0, 0), wxSize(1100, 1100));
	simulation_thread = new thread(&Frame::run, frame);
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

int Application::OnExit()
{
	if (simulation_thread->joinable()) {
		simulation_thread->join();
	}

	delete simulation_thread;
	return 0;
}


  // Add a "*/" in this line to play using command line observer (if you want to go back just copy it back into place)