; Auto-generated. Do not edit!


(cl:in-package message_tests-srv)


;//! \htmlinclude Changerate-request.msg.html

(cl:defclass <Changerate-request> (roslisp-msg-protocol:ros-message)
  ((newrate
    :reader newrate
    :initarg :newrate
    :type cl:float
    :initform 0.0))
)

(cl:defclass Changerate-request (<Changerate-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Changerate-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Changerate-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_tests-srv:<Changerate-request> is deprecated: use message_tests-srv:Changerate-request instead.")))

(cl:ensure-generic-function 'newrate-val :lambda-list '(m))
(cl:defmethod newrate-val ((m <Changerate-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_tests-srv:newrate-val is deprecated.  Use message_tests-srv:newrate instead.")
  (newrate m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Changerate-request>) ostream)
  "Serializes a message object of type '<Changerate-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'newrate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Changerate-request>) istream)
  "Deserializes a message object of type '<Changerate-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'newrate) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Changerate-request>)))
  "Returns string type for a service object of type '<Changerate-request>"
  "message_tests/ChangerateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Changerate-request)))
  "Returns string type for a service object of type 'Changerate-request"
  "message_tests/ChangerateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Changerate-request>)))
  "Returns md5sum for a message object of type '<Changerate-request>"
  "4c8b4fd3f5e2b2736a3c66de5e015351")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Changerate-request)))
  "Returns md5sum for a message object of type 'Changerate-request"
  "4c8b4fd3f5e2b2736a3c66de5e015351")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Changerate-request>)))
  "Returns full string definition for message of type '<Changerate-request>"
  (cl:format cl:nil "float64 newrate~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Changerate-request)))
  "Returns full string definition for message of type 'Changerate-request"
  (cl:format cl:nil "float64 newrate~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Changerate-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Changerate-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Changerate-request
    (cl:cons ':newrate (newrate msg))
))
;//! \htmlinclude Changerate-response.msg.html

(cl:defclass <Changerate-response> (roslisp-msg-protocol:ros-message)
  ((ret
    :reader ret
    :initarg :ret
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Changerate-response (<Changerate-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Changerate-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Changerate-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_tests-srv:<Changerate-response> is deprecated: use message_tests-srv:Changerate-response instead.")))

(cl:ensure-generic-function 'ret-val :lambda-list '(m))
(cl:defmethod ret-val ((m <Changerate-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_tests-srv:ret-val is deprecated.  Use message_tests-srv:ret instead.")
  (ret m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Changerate-response>) ostream)
  "Serializes a message object of type '<Changerate-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ret) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Changerate-response>) istream)
  "Deserializes a message object of type '<Changerate-response>"
    (cl:setf (cl:slot-value msg 'ret) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Changerate-response>)))
  "Returns string type for a service object of type '<Changerate-response>"
  "message_tests/ChangerateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Changerate-response)))
  "Returns string type for a service object of type 'Changerate-response"
  "message_tests/ChangerateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Changerate-response>)))
  "Returns md5sum for a message object of type '<Changerate-response>"
  "4c8b4fd3f5e2b2736a3c66de5e015351")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Changerate-response)))
  "Returns md5sum for a message object of type 'Changerate-response"
  "4c8b4fd3f5e2b2736a3c66de5e015351")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Changerate-response>)))
  "Returns full string definition for message of type '<Changerate-response>"
  (cl:format cl:nil "bool ret~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Changerate-response)))
  "Returns full string definition for message of type 'Changerate-response"
  (cl:format cl:nil "bool ret~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Changerate-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Changerate-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Changerate-response
    (cl:cons ':ret (ret msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Changerate)))
  'Changerate-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Changerate)))
  'Changerate-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Changerate)))
  "Returns string type for a service object of type '<Changerate>"
  "message_tests/Changerate")