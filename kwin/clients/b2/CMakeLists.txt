add_subdirectory( config ) 

########### next target ###############

set(kwin3_b2_PART_SRCS b2client.cpp)


kde4_add_plugin(kwin3_b2 ${kwin3_b2_PART_SRCS})

target_link_libraries(kwin3_b2 kdecorations ${X11_LIBRARIES})

install(TARGETS kwin3_b2  DESTINATION ${PLUGIN_INSTALL_DIR})


########### install files ###############

install( FILES b2.desktop  DESTINATION  ${DATA_INSTALL_DIR}/kwin/ )

