
########### next target ###############

set(kcm_kwindesktop_PART_SRCS main.cpp desktopnameswidget.cpp)
kde4_add_ui_files(kcm_kwindesktop_PART_SRCS main.ui)

kde4_add_plugin(kcm_kwindesktop ${kcm_kwindesktop_PART_SRCS})

target_link_libraries(kcm_kwindesktop  ${KDE4_KDEUI_LIBS} ${KDE4_KCMUTILS_LIBS} ${X11_LIBRARIES})

install(TARGETS kcm_kwindesktop  DESTINATION ${PLUGIN_INSTALL_DIR} )


########### install files ###############
install( FILES desktop.desktop DESTINATION  ${SERVICES_INSTALL_DIR} )

