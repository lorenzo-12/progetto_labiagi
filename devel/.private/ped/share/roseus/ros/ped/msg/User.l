;; Auto-generated. Do not edit!


(when (boundp 'ped::User)
  (if (not (find-package "PED"))
    (make-package "PED"))
  (shadow 'User (find-package "PED")))
(unless (find-package "PED::USER")
  (make-package "PED::USER"))

(in-package "ROS")
;;//! \htmlinclude User.msg.html


(defclass ped::User
  :super ros::object
  :slots (_name _x _y ))

(defmethod ped::User
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

(setf (get ped::User :md5sum-) "3d2ed4b4144493ed8a80311b20e21d00")
(setf (get ped::User :datatype-) "ped/User")
(setf (get ped::User :definition-)
      "string name
float32 x
float32 y

")



(provide :ped/User "3d2ed4b4144493ed8a80311b20e21d00")


