// Copyright (c) 2015, Matthew Malensek.
// Distributed under the BSD 2-Clause License (see LICENSE.txt for details)

#pragma once

#include <Windows.h>
#include <string>
#include <shellapi.h>

#define MSG_NOTIFYICON WM_APP + 200

class NotifyIcon {
public:
    NotifyIcon(HWND hWnd, std::wstring tip, HICON icon);
    ~NotifyIcon();

    NOTIFYICONDATA IconData();
    NOTIFYICONIDENTIFIER IconID();

    void Balloon(std::wstring title, std::wstring text, HICON icon = nullptr);
    void UpdateIcon(HICON icon);
    void UpdateToolTip(std::wstring newTip);

private:
    static int ids;

    HICON _icon;
    int _id;
    std::wstring _tip;

    NOTIFYICONDATA _nid;
    NOTIFYICONIDENTIFIER _nii;
};