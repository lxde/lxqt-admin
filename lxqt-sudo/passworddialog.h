/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXQt - a lightweight, Qt based, desktop toolset
 * http://lxqt.org
 *
 * Copyright: 2015 LXQt team
 * Authors:
 *   Palo Kisa <palo.kisa@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
    class PasswordDialog;
}

class Communication;
class QProcess;

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    PasswordDialog(QStringList argv
            , Communication & comm
            , QProcess & sudo
            , QWidget * parent = 0
            , Qt::WindowFlags f = 0);
    ~PasswordDialog();

    virtual void accept() override;
    virtual void hideEvent(QHideEvent * event) override;

private:
    QScopedPointer<Ui::PasswordDialog> ui;
    Communication & mComm;
    QProcess & mSudo;
};

#endif // PASSWORDDIALOG_H

