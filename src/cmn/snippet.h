#ifndef CMN_SNIPPET_H
#define CMN_SNIPPET_H

#define CREATE_CENTRAL_WIDGET_WITH_LAYOUT                  \
    QWidget *central_widget = new QWidget(this);           \
    central_widget->setObjectName("central-widget");       \
    this->setCentralWidget(central_widget);                \
    QHBoxLayout *layout = new QHBoxLayout(central_widget); \
    layout->setContentsMargins(0, 0, 0, 0);

#endif // CMN_SNIPPET_H
