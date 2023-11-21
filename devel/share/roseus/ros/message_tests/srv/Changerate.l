;; Auto-generated. Do not edit!


(when (boundp 'message_tests::Changerate)
  (if (not (find-package "MESSAGE_TESTS"))
    (make-package "MESSAGE_TESTS"))
  (shadow 'Changerate (find-package "MESSAGE_TESTS")))
(unless (find-package "MESSAGE_TESTS::CHANGERATE")
  (make-package "MESSAGE_TESTS::CHANGERATE"))
(unless (find-package "MESSAGE_TESTS::CHANGERATEREQUEST")
  (make-package "MESSAGE_TESTS::CHANGERATEREQUEST"))
(unless (find-package "MESSAGE_TESTS::CHANGERATERESPONSE")
  (make-package "MESSAGE_TESTS::CHANGERATERESPONSE"))

(in-package "ROS")





(defclass message_tests::ChangerateRequest
  :super ros::object
  :slots (_newrate ))

(defmethod message_tests::ChangerateRequest
  (:init
   (&key
    ((:newrate __newrate) 0.0)
    )
   (send-super :init)
   (setq _newrate (float __newrate))
   self)
  (:newrate
   (&optional __newrate)
   (if __newrate (setq _newrate __newrate)) _newrate)
  (:serialization-length
   ()
   (+
    ;; float64 _newrate
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _newrate
       (sys::poke _newrate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _newrate
     (setq _newrate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass message_tests::ChangerateResponse
  :super ros::object
  :slots (_ret ))

(defmethod message_tests::ChangerateResponse
  (:init
   (&key
    ((:ret __ret) nil)
    )
   (send-super :init)
   (setq _ret __ret)
   self)
  (:ret
   (&optional (__ret :null))
   (if (not (eq __ret :null)) (setq _ret __ret)) _ret)
  (:serialization-length
   ()
   (+
    ;; bool _ret
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ret
       (if _ret (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ret
     (setq _ret (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass message_tests::Changerate
  :super ros::object
  :slots ())

(setf (get message_tests::Changerate :md5sum-) "4c8b4fd3f5e2b2736a3c66de5e015351")
(setf (get message_tests::Changerate :datatype-) "message_tests/Changerate")
(setf (get message_tests::Changerate :request) message_tests::ChangerateRequest)
(setf (get message_tests::Changerate :response) message_tests::ChangerateResponse)

(defmethod message_tests::ChangerateRequest
  (:response () (instance message_tests::ChangerateResponse :init)))

(setf (get message_tests::ChangerateRequest :md5sum-) "4c8b4fd3f5e2b2736a3c66de5e015351")
(setf (get message_tests::ChangerateRequest :datatype-) "message_tests/ChangerateRequest")
(setf (get message_tests::ChangerateRequest :definition-)
      "float64 newrate
---
bool ret
")

(setf (get message_tests::ChangerateResponse :md5sum-) "4c8b4fd3f5e2b2736a3c66de5e015351")
(setf (get message_tests::ChangerateResponse :datatype-) "message_tests/ChangerateResponse")
(setf (get message_tests::ChangerateResponse :definition-)
      "float64 newrate
---
bool ret
")



(provide :message_tests/Changerate "4c8b4fd3f5e2b2736a3c66de5e015351")


