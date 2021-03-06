// Generated by gencpp from file ped/User.msg
// DO NOT EDIT!


#ifndef PED_MESSAGE_USER_H
#define PED_MESSAGE_USER_H


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
struct User_
{
  typedef User_<ContainerAllocator> Type;

  User_()
    : name()
    , x(0.0)
    , y(0.0)  {
    }
  User_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , x(0.0)
    , y(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;





  typedef boost::shared_ptr< ::ped::User_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ped::User_<ContainerAllocator> const> ConstPtr;

}; // struct User_

typedef ::ped::User_<std::allocator<void> > User;

typedef boost::shared_ptr< ::ped::User > UserPtr;
typedef boost::shared_ptr< ::ped::User const> UserConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ped::User_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ped::User_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ped::User_<ContainerAllocator1> & lhs, const ::ped::User_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ped::User_<ContainerAllocator1> & lhs, const ::ped::User_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ped

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ped::User_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ped::User_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::User_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ped::User_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::User_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ped::User_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ped::User_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d2ed4b4144493ed8a80311b20e21d00";
  }

  static const char* value(const ::ped::User_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d2ed4b4144493edULL;
  static const uint64_t static_value2 = 0x8a80311b20e21d00ULL;
};

template<class ContainerAllocator>
struct DataType< ::ped::User_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ped/User";
  }

  static const char* value(const ::ped::User_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ped::User_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n"
"float32 x\n"
"float32 y\n"
;
  }

  static const char* value(const ::ped::User_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ped::User_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.x);
      stream.next(m.y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct User_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ped::User_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ped::User_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PED_MESSAGE_USER_H
