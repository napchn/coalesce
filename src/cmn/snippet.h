#ifndef CMN_SNIPPET_H
#define CMN_SNIPPET_H

#define CREATE_WIDGET_WITH_LAYOUT(parent, name, objname, layout) \
    QWidget *name = new QWidget(parent);                         \
    name->setObjectName(objname);                                \
    layout *name##_layout = new layout(name);                    \
    name##_layout->setContentsMargins(0, 0, 0, 0);               \
    name##_layout->setSpacing(0);

#define INSTANTIATED_WIDGET(parent, name, objname, layout) \
    name = new QWidget(parent);                            \
    name->setObjectName(objname);                          \
    layout *name##_layout = new layout(name);              \
    name##_layout->setContentsMargins(0, 0, 0, 0);         \
    name##_layout->setSpacing(0);

#define INSTANTIATED_LAYOUT(parent, name, objname, layout) \
    QWidget *name = new QWidget(parent);                   \
    name->setObjectName(objname);                          \
    name##_layout = new layout(name);                      \
    name##_layout->setContentsMargins(0, 0, 0, 0);         \
    name##_layout->setSpacing(0);
#endif // CMN_SNIPPET_H
