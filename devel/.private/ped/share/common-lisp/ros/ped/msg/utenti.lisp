; Auto-generated. Do not edit!


(cl:in-package ped-msg)


;//! \htmlinclude utenti.msg.html

(cl:defclass <utenti> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (option
    :reader option
    :initarg :option
    :type cl:string
    :initform "")
   (pick
    :reader pick
    :initarg :pick
    :type cl:string
    :initform "")
   (delivery
    :reader delivery
    :initarg :delivery
    :type cl:string
    :initform "")
   (response
    :reader response
    :initarg :response
    :type cl:string
    :initform "")
   (stato
    :reader stato
    :initarg :stato
    :type cl:string
    :initform ""))
)

(cl:defclass utenti (<utenti>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <utenti>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'utenti)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ped-msg:<utenti> is deprecated: use ped-msg:utenti instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:name-val is deprecated.  Use ped-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'option-val :lambda-list '(m))
(cl:defmethod option-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:option-val is deprecated.  Use ped-msg:option instead.")
  (option m))

(cl:ensure-generic-function 'pick-val :lambda-list '(m))
(cl:defmethod pick-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:pick-val is deprecated.  Use ped-msg:pick instead.")
  (pick m))

(cl:ensure-generic-function 'delivery-val :lambda-list '(m))
(cl:defmethod delivery-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:delivery-val is deprecated.  Use ped-msg:delivery instead.")
  (delivery m))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:response-val is deprecated.  Use ped-msg:response instead.")
  (response m))

(cl:ensure-generic-function 'stato-val :lambda-list '(m))
(cl:defmethod stato-val ((m <utenti>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-msg:stato-val is deprecated.  Use ped-msg:stato instead.")
  (stato m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <utenti>) ostream)
  "Serializes a message object of type '<utenti>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'option))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'option))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'pick))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'pick))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'delivery))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'delivery))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'stato))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'stato))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <utenti>) istream)
  "Deserializes a message object of type '<utenti>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'option) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'option) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pick) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'pick) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'delivery) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'delivery) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stato) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'stato) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<utenti>)))
  "Returns string type for a message object of type '<utenti>"
  "ped/utenti")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'utenti)))
  "Returns string type for a message object of type 'utenti"
  "ped/utenti")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<utenti>)))
  "Returns md5sum for a message object of type '<utenti>"
  "eb76f3f6b8ca9967faa9c0f02b8c1ef7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'utenti)))
  "Returns md5sum for a message object of type 'utenti"
  "eb76f3f6b8ca9967faa9c0f02b8c1ef7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<utenti>)))
  "Returns full string definition for message of type '<utenti>"
  (cl:format cl:nil "string name~%string option~%string pick~%string delivery~%string response~%string stato~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'utenti)))
  "Returns full string definition for message of type 'utenti"
  (cl:format cl:nil "string name~%string option~%string pick~%string delivery~%string response~%string stato~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <utenti>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     4 (cl:length (cl:slot-value msg 'option))
     4 (cl:length (cl:slot-value msg 'pick))
     4 (cl:length (cl:slot-value msg 'delivery))
     4 (cl:length (cl:slot-value msg 'response))
     4 (cl:length (cl:slot-value msg 'stato))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <utenti>))
  "Converts a ROS message object to a list"
  (cl:list 'utenti
    (cl:cons ':name (name msg))
    (cl:cons ':option (option msg))
    (cl:cons ':pick (pick msg))
    (cl:cons ':delivery (delivery msg))
    (cl:cons ':response (response msg))
    (cl:cons ':stato (stato msg))
))
