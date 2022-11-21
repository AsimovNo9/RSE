;; Auto-generated. Do not edit!


(when (boundp 'ball_chaser::DriveToTarget)
  (if (not (find-package "BALL_CHASER"))
    (make-package "BALL_CHASER"))
  (shadow 'DriveToTarget (find-package "BALL_CHASER")))
(unless (find-package "BALL_CHASER::DRIVETOTARGET")
  (make-package "BALL_CHASER::DRIVETOTARGET"))
(unless (find-package "BALL_CHASER::DRIVETOTARGETREQUEST")
  (make-package "BALL_CHASER::DRIVETOTARGETREQUEST"))
(unless (find-package "BALL_CHASER::DRIVETOTARGETRESPONSE")
  (make-package "BALL_CHASER::DRIVETOTARGETRESPONSE"))

(in-package "ROS")





(defclass ball_chaser::DriveToTargetRequest
  :super ros::object
  :slots (_x _z ))

(defmethod ball_chaser::DriveToTargetRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _z (float __z))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass ball_chaser::DriveToTargetResponse
  :super ros::object
  :slots (_msg_feedback ))

(defmethod ball_chaser::DriveToTargetResponse
  (:init
   (&key
    ((:msg_feedback __msg_feedback) "")
    )
   (send-super :init)
   (setq _msg_feedback (string __msg_feedback))
   self)
  (:msg_feedback
   (&optional __msg_feedback)
   (if __msg_feedback (setq _msg_feedback __msg_feedback)) _msg_feedback)
  (:serialization-length
   ()
   (+
    ;; string _msg_feedback
    4 (length _msg_feedback)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _msg_feedback
       (write-long (length _msg_feedback) s) (princ _msg_feedback s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _msg_feedback
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _msg_feedback (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass ball_chaser::DriveToTarget
  :super ros::object
  :slots ())

(setf (get ball_chaser::DriveToTarget :md5sum-) "2088bdd400602a2cfa3a14d1f40d8ffc")
(setf (get ball_chaser::DriveToTarget :datatype-) "ball_chaser/DriveToTarget")
(setf (get ball_chaser::DriveToTarget :request) ball_chaser::DriveToTargetRequest)
(setf (get ball_chaser::DriveToTarget :response) ball_chaser::DriveToTargetResponse)

(defmethod ball_chaser::DriveToTargetRequest
  (:response () (instance ball_chaser::DriveToTargetResponse :init)))

(setf (get ball_chaser::DriveToTargetRequest :md5sum-) "2088bdd400602a2cfa3a14d1f40d8ffc")
(setf (get ball_chaser::DriveToTargetRequest :datatype-) "ball_chaser/DriveToTargetRequest")
(setf (get ball_chaser::DriveToTargetRequest :definition-)
      "float64 x
float64 z
---
string msg_feedback
")

(setf (get ball_chaser::DriveToTargetResponse :md5sum-) "2088bdd400602a2cfa3a14d1f40d8ffc")
(setf (get ball_chaser::DriveToTargetResponse :datatype-) "ball_chaser/DriveToTargetResponse")
(setf (get ball_chaser::DriveToTargetResponse :definition-)
      "float64 x
float64 z
---
string msg_feedback
")



(provide :ball_chaser/DriveToTarget "2088bdd400602a2cfa3a14d1f40d8ffc")


