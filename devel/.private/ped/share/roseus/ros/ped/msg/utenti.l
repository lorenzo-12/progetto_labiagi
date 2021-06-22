;; Auto-generated. Do not edit!


(when (boundp 'ped::utenti)
  (if (not (find-package "PED"))
    (make-package "PED"))
  (shadow 'utenti (find-package "PED")))
(unless (find-package "PED::UTENTI")
  (make-package "PED::UTENTI"))

(in-package "ROS")
;;//! \htmlinclude utenti.msg.html


(defclass ped::utenti
  :super ros::object
  :slots (_name _option _pick _delivery _response _stato ))

(defmethod ped::utenti
  (:init
   (&key
    ((:name __name) "")
    ((:option __option) "")
    ((:pick __pick) "")
    ((:delivery __delivery) "")
    ((:response __response) "")
    ((:stato __stato) "")
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _option (string __option))
   (setq _pick (string __pick))
   (setq _delivery (string __delivery))
   (setq _response (string __response))
   (setq _stato (string __stato))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:option
   (&optional __option)
   (if __option (setq _option __option)) _option)
  (:pick
   (&optional __pick)
   (if __pick (setq _pick __pick)) _pick)
  (:delivery
   (&optional __delivery)
   (if __delivery (setq _delivery __delivery)) _delivery)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:stato
   (&optional __stato)
   (if __stato (setq _stato __stato)) _stato)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; string _option
    4 (length _option)
    ;; string _pick
    4 (length _pick)
    ;; string _delivery
    4 (length _delivery)
    ;; string _response
    4 (length _response)
    ;; string _stato
    4 (length _stato)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; string _option
       (write-long (length _option) s) (princ _option s)
     ;; string _pick
       (write-long (length _pick) s) (princ _pick s)
     ;; string _delivery
       (write-long (length _delivery) s) (princ _delivery s)
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;; string _stato
       (write-long (length _stato) s) (princ _stato s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _option
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _option (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _pick
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _pick (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _delivery
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _delivery (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _stato
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _stato (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ped::utenti :md5sum-) "eb76f3f6b8ca9967faa9c0f02b8c1ef7")
(setf (get ped::utenti :datatype-) "ped/utenti")
(setf (get ped::utenti :definition-)
      "string name
string option
string pick
string delivery
string response
string stato

")



(provide :ped/utenti "eb76f3f6b8ca9967faa9c0f02b8c1ef7")


