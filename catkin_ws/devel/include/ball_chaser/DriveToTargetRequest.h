// Generated by gencpp from file ball_chaser/DriveToTargetRequest.msg
// DO NOT EDIT!


#ifndef BALL_CHASER_MESSAGE_DRIVETOTARGETREQUEST_H
#define BALL_CHASER_MESSAGE_DRIVETOTARGETREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ball_chaser
{
template <class ContainerAllocator>
struct DriveToTargetRequest_
{
  typedef DriveToTargetRequest_<ContainerAllocator> Type;

  DriveToTargetRequest_()
    : x(0.0)
    , z(0.0)  {
    }
  DriveToTargetRequest_(const ContainerAllocator& _alloc)
    : x(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DriveToTargetRequest_

typedef ::ball_chaser::DriveToTargetRequest_<std::allocator<void> > DriveToTargetRequest;

typedef boost::shared_ptr< ::ball_chaser::DriveToTargetRequest > DriveToTargetRequestPtr;
typedef boost::shared_ptr< ::ball_chaser::DriveToTargetRequest const> DriveToTargetRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator1> & lhs, const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.z == rhs.z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator1> & lhs, const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ball_chaser

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fe27dff9cb3614cf148525a3f98d6136";
  }

  static const char* value(const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfe27dff9cb3614cfULL;
  static const uint64_t static_value2 = 0x148525a3f98d6136ULL;
};

template<class ContainerAllocator>
struct DataType< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ball_chaser/DriveToTargetRequest";
  }

  static const char* value(const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n"
"float64 z\n"
;
  }

  static const char* value(const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DriveToTargetRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ball_chaser::DriveToTargetRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ball_chaser::DriveToTargetRequest_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BALL_CHASER_MESSAGE_DRIVETOTARGETREQUEST_H
