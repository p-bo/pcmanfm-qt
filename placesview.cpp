/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include "placesview.h"
#include "placesmodel.h"

using namespace Fm;

PlacesView::PlacesView(QWidget* parent): QTreeView(parent) {
  setRootIsDecorated(false);
  setHeaderHidden(true);
  setIndentation(12);
  
  connect(this, SIGNAL(clicked(QModelIndex)), SLOT(clicked(QModelIndex)));
  
  setIconSize(QSize(24, 24));
  
  model_ = new PlacesModel(this);
  setModel(model_);
  expandAll();
}

void PlacesView::clicked(const QModelIndex& index) {
  qDebug("clicked!!");
}

void PlacesView::dragMoveEvent(QDragMoveEvent* event) {
  QTreeView::dragMoveEvent(event);
}

void PlacesView::dropEvent(QDropEvent* event) {
  QAbstractItemView::dropEvent(event);
}

void PlacesView::contextMenuEvent(QContextMenuEvent* event) {
  QAbstractScrollArea::contextMenuEvent(event);
}

PlacesView::~PlacesView() {
}

void PlacesView::chdir(FmPath* path) {
  
}

#include "placesview.moc"
