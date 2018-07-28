void IbusPlatformInputContext::showInputPanel(){
#ifdef DM_DEBUG_KEYBAORD
    qDebug() << "show keyboard" << endl;
    //setFocusObject(QApplication::focusObject());

    qDebug() << "-IPU- keyboard-->focusObject:" << QApplication::focusObject() << endl;
    qDebug() << "-IPU- keyboard-->activeWindow:" << QApplication::activeWindow();
    qDebug() << "-IPU- keyboard-->activeModalWidget:" << QApplication::activeModalWidget();
#endif
    //Qt::WindowFlags wFlag = d->m_chinesekeyboard->windowFlags();
    //wFlag = wFlag | Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus;
    //d->m_chinesekeyboard->setParent(Q_NULLPTR, wFlag);
    QWidget *w = qobject_cast<QWidget*>(QApplication::focusObject()); // 焦点控件
//if (w->inherits("QLineEdit") || w->inherits("QSpinBox") || w->inherits("QTextEdit") || w->inherits("QDoubleSpinBox")
//    || (w->inherits("QComboBox") && static_cast<QComboBox *>(w)->isEditable())) {
//    
//}
//else 
//{
//    return;
//}
//#ifdef Q_OS_WIN
    QWidget * actWidget = QApplication::activeWindow();
    qDebug() << "inherits:" << actWidget->inherits("DmMessageBox");
    if ((Q_NULLPTR != actWidget) && (false == actWidget->inherits("DmMessageBox")) && (actWidget->inherits("QDialog"))) {
        // 重设父类和窗口标志
#ifdef Q_OS_WIN
        // Qt::WindowFlags flag = wFlag | Qt::WindowDoesNotAcceptFocus | Qt::FramelessWindowHint |
        //    Qt::WindowStaysOnTopHint | Qt::Tool;
#else
        //Qt::WindowFlags flag = wFlag | Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus;
        //setWindowFlags(windowFlags() | Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::ForeignWindow);
#endif
        d->m_chinesekeyboard->setParent(actWidget);
    }
    d->m_chinesekeyboard->setWindowFlags(Qt::WindowDoesNotAcceptFocus | Qt::FramelessWindowHint |
        Qt::WindowStaysOnTopHint | Qt::Tool | Qt::X11BypassWindowManagerHint); //设置
                                                                               // 如果当前窗口不可见，则显示出来;
    if (!d->m_chinesekeyboard->isVisible())
    {
        d->m_chinesekeyboard->setVisible(true);
    }
    //#endif

    //QPlatformInputContext::showInputPanel();
}
