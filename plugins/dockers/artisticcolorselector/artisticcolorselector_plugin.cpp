/*
 *  Copyright (c) 2009 Cyrille Berger <cberger@cberger.net>
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "artisticcolorselector_plugin.h"
#include "artisticcolorselector_dock.h"

#include <kpluginfactory.h>
#include <klocalizedstring.h>
#include <KoDockFactoryBase.h>
#include <KoDockRegistry.h>

K_PLUGIN_FACTORY_WITH_JSON(PaletteDockPluginFactory, "krita_artisticcolorselector.json", registerPlugin<ArtisticColorSelectorPlugin>();)

class ArtisticColorSelectorDockFactory: public KoDockFactoryBase
{
public:
    QString id() const override {
        return QString("ArtisticColorSelector");
    }

    virtual Qt::DockWidgetArea defaultDockWidgetArea() const {
        return Qt::RightDockWidgetArea;
    }

    QDockWidget* createDockWidget() override {
        ArtisticColorSelectorDock* dockWidget = new ArtisticColorSelectorDock();
        dockWidget->setObjectName(id());
        return dockWidget;
    }

    DockPosition defaultDockPosition() const override {
        return DockMinimized;
    }
};


ArtisticColorSelectorPlugin::ArtisticColorSelectorPlugin(QObject* parent, const QVariantList &):
    QObject(parent)
{
    KoDockRegistry::instance()->add(new ArtisticColorSelectorDockFactory());
}

#include "artisticcolorselector_plugin.moc"
