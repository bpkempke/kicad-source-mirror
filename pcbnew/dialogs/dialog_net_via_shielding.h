/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2014 John Beard, john.j.beard@gmail.com
 * Copyright (C) 1992-2014 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef __DIALOG_NET_VIA_SHIELDING__
#define __DIALOG_NET_VIA_SHIELDING__

// Include the wxFormBuider header base:
#include <vector>
#include <dialog_net_via_shielding_base.h>

class DIALOG_NET_VIA_SHIELDING : public DIALOG_NET_VIA_SHIELDING_BASE
{
private:

    int& m_viaStandoff;
    int& m_viaSpacing;
    int& m_viaDiameter;
    int& m_viaDrill;

public:
    // Constructor and destructor
    DIALOG_NET_VIA_SHIELDING( PCB_BASE_FRAME* aParent, int& viaStandoff, int& viaSpacing, int& viaDiameter, int& viaDrill );
    ~DIALOG_NET_VIA_SHIELDING();

private:

    /*!
     * Reset a text field to be 0 if it was exited while blank
     */
    void OnTextFocusLost( wxFocusEvent& event );

    void OnCancelClick( wxCommandEvent& event );
    void OnOkClick( wxCommandEvent& event );

    /**
     * Persistent dialog options
     */
    struct ZONE_NET_SHIELDING_OPTIONS
    {
        double  viaStandoff;
        double  viaSpacing;
        double  viaDiameter;
        double  viaDrill;

        ZONE_NET_SHIELDING_OPTIONS():
            viaStandoff(0),
            viaSpacing(0),
            viaDiameter(0),
            viaDrill(0)
        {
        }
    };

    // persistent settings
    static ZONE_NET_SHIELDING_OPTIONS m_options;
};

#endif      //  __DIALOG_NET_VIA_SHIELDING__
