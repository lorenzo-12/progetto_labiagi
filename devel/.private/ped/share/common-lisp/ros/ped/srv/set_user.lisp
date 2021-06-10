; Auto-generated. Do not edit!


(cl:in-package ped-srv)


;//! \htmlinclude set_user-request.msg.html

(cl:defclass <set_user-request> (roslisp-msg-protocol:ros-message)
  ((azione
    :reader azione
    :initarg :azione
    :type cl:string
    :initform "")
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass set_user-request (<set_user-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_user-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_user-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ped-srv:<set_user-request> is deprecated: use ped-srv:set_user-request instead.")))

(cl:ensure-generic-function 'azione-val :lambda-list '(m))
(cl:defmethod azione-val ((m <set_user-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-srv:azione-val is deprecated.  Use ped-srv:azione instead.")
  (azione m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <set_user-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-srv:name-val is deprecated.  Use ped-srv:name instead.")
  (name m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <set_user-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-srv:x-val is deprecated.  Use ped-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <set_user-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-srv:y-val is deprecated.  Use ped-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_user-request>) ostream)
  "Serializes a message object of type '<set_user-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'azione))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'azione))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_user-request>) istream)
  "Deserializes a message object of type '<set_user-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'azione) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'azione) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_user-request>)))
  "Returns string type for a service object of type '<set_user-request>"
  "ped/set_userRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_user-request)))
  "Returns string type for a service object of type 'set_user-request"
  "ped/set_userRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_user-request>)))
  "Returns md5sum for a message object of type '<set_user-request>"
  "22d2aef14551e2abcdbc9a7b477b5fa6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_user-request)))
  "Returns md5sum for a message object of type 'set_user-request"
  "22d2aef14551e2abcdbc9a7b477b5fa6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_user-request>)))
  "Returns full string definition for message of type '<set_user-request>"
  (cl:format cl:nil "string azione~%string name~%float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_user-request)))
  "Returns full string definition for message of type 'set_user-request"
  (cl:format cl:nil "string azione~%string name~%float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_user-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'azione))
     4 (cl:length (cl:slot-value msg 'name))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_user-request>))
  "Converts a ROS message object to a list"
  (cl:list 'set_user-request
    (cl:cons ':azione (azione msg))
    (cl:cons ':name (name msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
;//! \htmlinclude set_user-response.msg.html

(cl:defclass <set_user-response> (roslisp-msg-protocol:ros-message)
  ((ret
    :reader ret
    :initarg :ret
    :type cl:string
    :initform ""))
)

(cl:defclass set_user-response (<set_user-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_user-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_user-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ped-srv:<set_user-response> is deprecated: use ped-srv:set_user-response instead.")))

(cl:ensure-generic-function 'ret-val :lambda-list '(m))
(cl:defmethod ret-val ((m <set_user-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ped-srv:ret-val is deprecated.  Use ped-srv:ret instead.")
  (ret m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_user-response>) ostream)
  "Serializes a message object of type '<set_user-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'ret))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'ret))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_user-response>) istream)
  "Deserializes a message object of type '<set_user-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ret) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'ret) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_user-response>)))
  "Returns string type for a service object of type '<set_user-response>"
  "ped/set_userResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_user-response)))
  "Returns string type for a service object of type 'set_user-response"
  "ped/set_userResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_user-response>)))
  "Returns md5sum for a message object of type '<set_user-response>"
  "22d2aef14551e2abcdbc9a7b477b5fa6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_user-response)))
  "Returns md5sum for a message object of type 'set_user-response"
  "22d2aef14551e2abcdbc9a7b477b5fa6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_user-response>)))
  "Returns full string definition for message of type '<set_user-response>"
  (cl:format cl:nil "string ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_user-response)))
  "Returns full string definition for message of type 'set_user-response"
  (cl:format cl:nil "string ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_user-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'ret))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_user-response>))
  "Converts a ROS message object to a list"
  (cl:list 'set_user-response
    (cl:cons ':ret (ret msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'set_user)))
  'set_user-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'set_user)))
  'set_user-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_user)))
  "Returns string type for a service object of type '<set_user>"
  "ped/set_user")