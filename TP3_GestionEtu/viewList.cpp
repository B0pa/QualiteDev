#include "viewList.h"
#include "controllers.h"

ViewList::ViewList(Promotion* promo, QListWidget* list):promo(promo), list(list)
{
    update();
}


void ViewList::update()
{
    list->clear();

    list->addItems(promo->getList());
}

void ViewList::remove()
{
    QList<QListWidgetItem*> items = list->selectedItems();
    QStringList listStringSelected;
    for (QListWidgetItem*  item : items)
    {
        listStringSelected.append(item->text());
    }

    ControllerRemoveList controller(promo);
    controller.control(listStringSelected);
}
