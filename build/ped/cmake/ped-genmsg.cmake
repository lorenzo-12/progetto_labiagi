# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ped: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iped:/home/me/progetto_labiagi/src/ped/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ped_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_custom_target(_ped_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ped" "/home/me/progetto_labiagi/src/ped/msg/User.msg" ""
)

get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_custom_target(_ped_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ped" "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ped
  "/home/me/progetto_labiagi/src/ped/msg/User.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ped
)

### Generating Services
_generate_srv_cpp(ped
  "/home/me/progetto_labiagi/src/ped/srv/set_user.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ped
)

### Generating Module File
_generate_module_cpp(ped
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ped
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ped_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ped_generate_messages ped_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_dependencies(ped_generate_messages_cpp _ped_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_dependencies(ped_generate_messages_cpp _ped_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ped_gencpp)
add_dependencies(ped_gencpp ped_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ped_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(ped
  "/home/me/progetto_labiagi/src/ped/msg/User.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ped
)

### Generating Services
_generate_srv_eus(ped
  "/home/me/progetto_labiagi/src/ped/srv/set_user.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ped
)

### Generating Module File
_generate_module_eus(ped
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ped
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(ped_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(ped_generate_messages ped_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_dependencies(ped_generate_messages_eus _ped_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_dependencies(ped_generate_messages_eus _ped_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ped_geneus)
add_dependencies(ped_geneus ped_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ped_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ped
  "/home/me/progetto_labiagi/src/ped/msg/User.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ped
)

### Generating Services
_generate_srv_lisp(ped
  "/home/me/progetto_labiagi/src/ped/srv/set_user.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ped
)

### Generating Module File
_generate_module_lisp(ped
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ped
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ped_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ped_generate_messages ped_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_dependencies(ped_generate_messages_lisp _ped_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_dependencies(ped_generate_messages_lisp _ped_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ped_genlisp)
add_dependencies(ped_genlisp ped_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ped_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(ped
  "/home/me/progetto_labiagi/src/ped/msg/User.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ped
)

### Generating Services
_generate_srv_nodejs(ped
  "/home/me/progetto_labiagi/src/ped/srv/set_user.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ped
)

### Generating Module File
_generate_module_nodejs(ped
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ped
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(ped_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(ped_generate_messages ped_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_dependencies(ped_generate_messages_nodejs _ped_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_dependencies(ped_generate_messages_nodejs _ped_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ped_gennodejs)
add_dependencies(ped_gennodejs ped_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ped_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ped
  "/home/me/progetto_labiagi/src/ped/msg/User.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped
)

### Generating Services
_generate_srv_py(ped
  "/home/me/progetto_labiagi/src/ped/srv/set_user.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped
)

### Generating Module File
_generate_module_py(ped
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ped_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ped_generate_messages ped_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/msg/User.msg" NAME_WE)
add_dependencies(ped_generate_messages_py _ped_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/me/progetto_labiagi/src/ped/srv/set_user.srv" NAME_WE)
add_dependencies(ped_generate_messages_py _ped_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ped_genpy)
add_dependencies(ped_genpy ped_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ped_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ped)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ped
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ped_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ped)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ped
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(ped_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ped)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ped
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ped_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ped)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ped
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(ped_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ped
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ped_generate_messages_py std_msgs_generate_messages_py)
endif()
