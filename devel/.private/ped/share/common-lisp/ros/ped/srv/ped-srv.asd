
(cl:in-package :asdf)

(defsystem "ped-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "set_user" :depends-on ("_package_set_user"))
    (:file "_package_set_user" :depends-on ("_package"))
  ))