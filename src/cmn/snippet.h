#ifndef CMN_SNIPPET_H
#define CMN_SNIPPET_H

#define CREATE_WIDGET_WITH_LAYOUT(parent, name, objname) \
    QWidget *name = new QWidget(parent);                 \
    left_area->setObjectName(objname);                   \
    QVBoxLayout *name##_layout = new QVBoxLayout(name);  \
    name##_layout->setContentsMargins(0, 0, 0, 0);

#endif // CMN_SNIPPET_H
