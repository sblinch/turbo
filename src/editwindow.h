#ifndef TVEDIT_EDITWINDOW_H
#define TVEDIT_EDITWINDOW_H

#define Uses_TWindow
#include <tvision/tv.h>

#include "tscintilla.h"
#include "drawview.h"

class DocumentView;

struct EditorWindow : public TWindow, Scintilla::TScintillaWindow {

    EditorWindow(const TRect &bounds);

    DocumentView *docView;
    TDrawSubView *leftMargin;
    TScrollBar *vScrollBar;
    bool drawing;

    Scintilla::TScintillaEditor editor;
    TDrawableView editorView;

    TRect editorBounds() const;
    void setUpEditor();
    void redrawEditor();
    void setActive(Boolean enable);

    void handleEvent(TEvent &ev) override;
    void changeBounds(const TRect &bounds) override;

    void lockSubViews();
    void unlockSubViews();
    void scrollBarEvent(TEvent ev);
    bool scrollBarChanged(TScrollBar *bar);
    void setVerticalScrollPos(int delta, int limit, int size) override;

};

#endif
