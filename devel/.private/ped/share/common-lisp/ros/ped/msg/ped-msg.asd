
(cl:in-package :asdf)

(defsystem "ped-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "User" :depends-on ("_package_User"))
    (:file "_package_User" :depends-on ("_package"))
  ))