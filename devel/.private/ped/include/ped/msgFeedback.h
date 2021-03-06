// Generated by gencpp from file ped/msgFeedback.msg
// DO NOT EDIT!


#ifndef PED_MESSAGE_MSGFEEDBACK_H
#define PED_MESSAGE_MSGFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ped
{
template <class ContainerAllocator>
struct msgFeedback_
{
  typedef msgFeedback_<ContainerAllocator> Type;

  msgFeedback_()
    : feedback()  {
    }
  msgFeedback_(const ContainerAllocator& _alloc)
    : feedback(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _feedback_type;
  _feedback_type feedback;





  typedef boost::shared_ptr< ::ped::msgFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ped::msgFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct msgFeedback_

typedef ::ped::msgFeedback_<std::allocator<void> > msgFeedback;

typedef boost::shared_ptr< ::ped::msgFeedback > msgFeedbackPtr;
typedef boost::shared_ptr< ::ped::msgFeedback const> msgFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ped::msgFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ped::msgFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ped::msgFeedback_<ContainerAllocator1> & lhs, const ::ped::msgFeedback_<ContainerAllocator2> & rhs)
{
  return lhs.feedback == rhs.feedback;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ped::msgFeedback_<ContainerAllocator1> & lhs, const ::ped::msgFeedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ped

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ped::msgFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ped::msgFeedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::msgFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::msgFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::msgFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::msgFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ped::msgFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c14cdf907e5c7c7fd47292add15660f0";
  }

  static const char* value(const ::ped::msgFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc14cdf907e5c7c7fULL;
  static const uint64_t static_value2 = 0xd47292add15660f0ULL;
};

template<class ContainerAllocator>
struct DataType< ::ped::msgFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ped/msgFeedback";
  }

  static const char* value(const ::ped::msgFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ped::msgFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#feedback\n"
"string feedback\n"
"\n"
;
  }

  static const char* value(const ::ped::msgFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ped::msgFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msgFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ped::msgFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ped::msgFeedback_<ContainerAllocator>& v)
  {
    s << indent << "feedback: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PED_MESSAGE_MSGFEEDBACK_H
