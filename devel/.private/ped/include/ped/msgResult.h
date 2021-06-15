// Generated by gencpp from file ped/msgResult.msg
// DO NOT EDIT!


#ifndef PED_MESSAGE_MSGRESULT_H
#define PED_MESSAGE_MSGRESULT_H


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
struct msgResult_
{
  typedef msgResult_<ContainerAllocator> Type;

  msgResult_()
    : result()  {
    }
  msgResult_(const ContainerAllocator& _alloc)
    : result(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::ped::msgResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ped::msgResult_<ContainerAllocator> const> ConstPtr;

}; // struct msgResult_

typedef ::ped::msgResult_<std::allocator<void> > msgResult;

typedef boost::shared_ptr< ::ped::msgResult > msgResultPtr;
typedef boost::shared_ptr< ::ped::msgResult const> msgResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ped::msgResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ped::msgResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ped::msgResult_<ContainerAllocator1> & lhs, const ::ped::msgResult_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ped::msgResult_<ContainerAllocator1> & lhs, const ::ped::msgResult_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ped

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ped::msgResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ped::msgResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::msgResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::msgResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::msgResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::msgResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ped::msgResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c22f2a1ed8654a0b365f1bb3f7ff2c0f";
  }

  static const char* value(const ::ped::msgResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc22f2a1ed8654a0bULL;
  static const uint64_t static_value2 = 0x365f1bb3f7ff2c0fULL;
};

template<class ContainerAllocator>
struct DataType< ::ped::msgResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ped/msgResult";
  }

  static const char* value(const ::ped::msgResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ped::msgResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#result definition\n"
"string result\n"
;
  }

  static const char* value(const ::ped::msgResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ped::msgResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msgResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ped::msgResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ped::msgResult_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PED_MESSAGE_MSGRESULT_H