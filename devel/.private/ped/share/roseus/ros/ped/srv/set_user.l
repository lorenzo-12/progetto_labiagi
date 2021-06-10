;; Auto-generated. Do not edit!


(when (boundp 'ped::set_user)
  (if (not (find-package "PED"))
    (make-package "PED"))
  (shadow 'set_user (find-package "PED")))
(unless (find-package "PED::SET_USER")
  (make-package "PED::SET_USER"))
(unless (find-package "PED::SET_USERREQUEST")
  (make-package "PED::SET_USERREQUEST"))
(unless (find-package "PED::SET_USERRESPONSE")
  (make-package "PED::SET_USERRESPONSE"))

(in-package "ROS")





(defclass ped::set_userRequest
  :super ros::object
  :slots (_name _x _y ))

(defmethod ped::set_userRequest
  (:init
   (&key
    ((:name __name) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _x (float __x))
   (setq _y (float __y))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; float32 _x
    4
    ;; float32 _y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ped::set_userResponse
  :super ros::object
  :slots (_ret ))

(defmethod ped::set_userResponse
  (:init
   (&key
    ((:ret __ret) "")
    )
   (send-super :init)
   (setq _ret (string __ret))
   self)
  (:ret
   (&optional __ret)
   (if __ret (setq _ret __ret)) _ret)
  (:serialization-length
   ()
   (+
    ;; string _ret
    4 (length _ret)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _ret
       (write-long (length _ret) s) (princ _ret s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _ret
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _ret (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass ped::set_user
  :super ros::object
  :slots ())

(setf (get ped::set_user :md5sum-) "f767d19539c13d1e285b77b3522bdee4")
(setf (get ped::set_user :datatype-) "ped/set_user")
(setf (get ped::set_user :request) ped::set_userRequest)
(setf (get ped::set_user :response) ped::set_userResponse)

(defmethod ped::set_userRequest
  (:response () (instance ped::set_userResponse :init)))

(setf (get ped::set_userRequest :md5sum-) "f767d19539c13d1e285b77b3522bdee4")
(setf (get ped::set_userRequest :datatype-) "ped/set_userRequest")
(setf (get ped::set_userRequest :definition-)
      "string name
float32 x
float32 y
---
string ret

")

(setf (get ped::set_userResponse :md5sum-) "f767d19539c13d1e285b77b3522bdee4")
(setf (get ped::set_userResponse :datatype-) "ped/set_userResponse")
(setf (get ped::set_userResponse :definition-)
      "string name
float32 x
float32 y
---
string ret

")



(provide :ped/set_user "f767d19539c13d1e285b77b3522bdee4")


