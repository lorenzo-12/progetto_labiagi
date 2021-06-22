
(cl:in-package :asdf)

(defsystem "ped-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "utenti" :depends-on ("_package_utenti"))
    (:file "_package_utenti" :depends-on ("_package"))
  ))