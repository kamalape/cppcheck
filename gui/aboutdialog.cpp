/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2009 Daniel Marjam�ki and Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "aboutdialog.h"

AboutDialog::AboutDialog(const QString &version, QWidget *parent)
        : QDialog(parent)
        , mVersion(version)
{
    setWindowTitle(tr("About cppcheck"));
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *btnLayout = new QHBoxLayout(this);

    QLabel *name = new QLabel(tr("Cppcheck - A tool for static C/C++ code analysis."));
    QLabel *ver = new QLabel(QString(tr("Version %1")).arg(mVersion));
    QLabel *copy = new QLabel(("Copyright (C) 2007-2009 Daniel Marjam�ki and cppcheck team."));
    copy->setWordWrap(true);
    QLabel *gpl = new QLabel(tr("This program is licensed under the terms " \
                                "of the GNU General Public License version 3"));
    gpl->setWordWrap(true);
    QPushButton *quit = new QPushButton(tr("Close"));

    mainLayout->addWidget(name);
    mainLayout->addWidget(ver);
    mainLayout->addWidget(copy);
    mainLayout->addWidget(gpl);
    mainLayout->addStretch();

    mainLayout->addLayout(btnLayout);
    btnLayout->addStretch();
    btnLayout->addWidget(quit);

    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}
