//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2014. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MOVE_DETAIL_FWD_MACROS_HPP
#define BOOST_MOVE_DETAIL_FWD_MACROS_HPP

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/move/detail/workaround.hpp>

namespace boost {
namespace move_detail {

template <typename T> struct unvoid { typedef T type; };
template <> struct unvoid<void> { struct type { }; };
template <> struct unvoid<const void> { struct type { }; };

}  //namespace move_detail {
}  //namespace boost {

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#if defined(BOOST_MOVE_MSVC_10_MEMBER_RVALUE_REF_BUG)

namespace boost {
namespace move_detail {

   template<class T>
   struct mref;

   template<class T>
   struct mref<T &>
   {
      explicit mref(T &t) : t_(t){}
      T &t_;
      T & get() {  return t_;   }
   };

   template<class T>
   struct mref
   {
      explicit mref(T &&t) : t_(t) {}
      T &t_;
      T &&get() {  return ::boost::move(t_);   }
   };

}  //namespace move_detail {
}  //namespace boost {

#endif   //BOOST_MOVE_MSVC_10_MEMBER_RVALUE_REF_BUG
#endif   //!defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

//BOOST_MOVE_REPEATN(MACRO)
#define BOOST_MOVE_REPEAT0(MACRO)
#define BOOST_MOVE_REPEAT1(MACRO) MACRO
#define BOOST_MOVE_REPEAT2(MACRO) BOOST_MOVE_REPEAT1(MACRO), MACRO
#define BOOST_MOVE_REPEAT3(MACRO) BOOST_MOVE_REPEAT2(MACRO), MACRO
#define BOOST_MOVE_REPEAT4(MACRO) BOOST_MOVE_REPEAT3(MACRO), MACRO
#define BOOST_MOVE_REPEAT5(MACRO) BOOST_MOVE_REPEAT4(MACRO), MACRO
#define BOOST_MOVE_REPEAT6(MACRO) BOOST_MOVE_REPEAT5(MACRO), MACRO
#define BOOST_MOVE_REPEAT7(MACRO) BOOST_MOVE_REPEAT6(MACRO), MACRO
#define BOOST_MOVE_REPEAT8(MACRO) BOOST_MOVE_REPEAT7(MACRO), MACRO
#define BOOST_MOVE_REPEAT9(MACRO) BOOST_MOVE_REPEAT8(MACRO), MACRO

//BOOST_MOVE_FWDN
#define BOOST_MOVE_FWD0
#define BOOST_MOVE_FWD1 ::boost::forward<P0>(p0)
#define BOOST_MOVE_FWD2 BOOST_MOVE_FWD1, ::boost::forward<P1>(p1)
#define BOOST_MOVE_FWD3 BOOST_MOVE_FWD2, ::boost::forward<P2>(p2)
#define BOOST_MOVE_FWD4 BOOST_MOVE_FWD3, ::boost::forward<P3>(p3)
#define BOOST_MOVE_FWD5 BOOST_MOVE_FWD4, ::boost::forward<P4>(p4)
#define BOOST_MOVE_FWD6 BOOST_MOVE_FWD5, ::boost::forward<P5>(p5)
#define BOOST_MOVE_FWD7 BOOST_MOVE_FWD6, ::boost::forward<P6>(p6)
#define BOOST_MOVE_FWD8 BOOST_MOVE_FWD7, ::boost::forward<P7>(p7)
#define BOOST_MOVE_FWD9 BOOST_MOVE_FWD8, ::boost::forward<P8>(p8)

//BOOST_MOVE_FWDQN
#define BOOST_MOVE_FWDQ0
#define BOOST_MOVE_FWDQ1 ::boost::forward<Q0>(q0)
#define BOOST_MOVE_FWDQ2 BOOST_MOVE_FWDQ1, ::boost::forward<Q1>(q1)
#define BOOST_MOVE_FWDQ3 BOOST_MOVE_FWDQ2, ::boost::forward<Q2>(q2)
#define BOOST_MOVE_FWDQ4 BOOST_MOVE_FWDQ3, ::boost::forward<Q3>(q3)
#define BOOST_MOVE_FWDQ5 BOOST_MOVE_FWDQ4, ::boost::forward<Q4>(q4)
#define BOOST_MOVE_FWDQ6 BOOST_MOVE_FWDQ5, ::boost::forward<Q5>(q5)
#define BOOST_MOVE_FWDQ7 BOOST_MOVE_FWDQ6, ::boost::forward<Q6>(q6)
#define BOOST_MOVE_FWDQ8 BOOST_MOVE_FWDQ7, ::boost::forward<Q7>(q7)
#define BOOST_MOVE_FWDQ9 BOOST_MOVE_FWDQ8, ::boost::forward<Q8>(q8)

//BOOST_MOVE_ARGN
#define BOOST_MOVE_ARG0
#define BOOST_MOVE_ARG1 p0
#define BOOST_MOVE_ARG2 BOOST_MOVE_ARG1, p1
#define BOOST_MOVE_ARG3 BOOST_MOVE_ARG2, p2
#define BOOST_MOVE_ARG4 BOOST_MOVE_ARG3, p3
#define BOOST_MOVE_ARG5 BOOST_MOVE_ARG4, p4
#define BOOST_MOVE_ARG6 BOOST_MOVE_ARG5, p5
#define BOOST_MOVE_ARG7 BOOST_MOVE_ARG6, p6
#define BOOST_MOVE_ARG8 BOOST_MOVE_ARG7, p7
#define BOOST_MOVE_ARG9 BOOST_MOVE_ARG8, p8

//BOOST_MOVE_DECLVALN
#define BOOST_MOVE_DECLVAL0
#define BOOST_MOVE_DECLVAL1 ::boost::move_detail::declval<P0>()
#define BOOST_MOVE_DECLVAL2 BOOST_MOVE_DECLVAL1, ::boost::move_detail::declval<P1>()
#define BOOST_MOVE_DECLVAL3 BOOST_MOVE_DECLVAL2, ::boost::move_detail::declval<P2>()
#define BOOST_MOVE_DECLVAL4 BOOST_MOVE_DECLVAL3, ::boost::move_detail::declval<P3>()
#define BOOST_MOVE_DECLVAL5 BOOST_MOVE_DECLVAL4, ::boost::move_detail::declval<P4>()
#define BOOST_MOVE_DECLVAL6 BOOST_MOVE_DECLVAL5, ::boost::move_detail::declval<P5>()
#define BOOST_MOVE_DECLVAL7 BOOST_MOVE_DECLVAL6, ::boost::move_detail::declval<P6>()
#define BOOST_MOVE_DECLVAL8 BOOST_MOVE_DECLVAL7, ::boost::move_detail::declval<P7>()
#define BOOST_MOVE_DECLVAL9 BOOST_MOVE_DECLVAL8, ::boost::move_detail::declval<P8>()

#ifdef BOOST_MOVE_MSVC_10_MEMBER_RVALUE_REF_BUG
   #define BOOST_MOVE_MREF(T)    ::boost::move_detail::mref<T>
   #define BOOST_MOVE_MFWD(N)    ::boost::forward<P##N>(this->m_p##N.get())
#else
   #define BOOST_MOVE_MREF(T)    BOOST_FWD_REF(T)
   #define BOOST_MOVE_MFWD(N)    ::boost::forward<P##N>(this->m_p##N)
#endif
#define BOOST_MOVE_MITFWD(N)  *this->m_p##N
#define BOOST_MOVE_MINC(N)    ++this->m_p##N

//BOOST_MOVE_MFWDN
#define BOOST_MOVE_MFWD0
#define BOOST_MOVE_MFWD1 BOOST_MOVE_MFWD(0)
#define BOOST_MOVE_MFWD2 BOOST_MOVE_MFWD1, BOOST_MOVE_MFWD(1)
#define BOOST_MOVE_MFWD3 BOOST_MOVE_MFWD2, BOOST_MOVE_MFWD(2)
#define BOOST_MOVE_MFWD4 BOOST_MOVE_MFWD3, BOOST_MOVE_MFWD(3)
#define BOOST_MOVE_MFWD5 BOOST_MOVE_MFWD4, BOOST_MOVE_MFWD(4)
#define BOOST_MOVE_MFWD6 BOOST_MOVE_MFWD5, BOOST_MOVE_MFWD(5)
#define BOOST_MOVE_MFWD7 BOOST_MOVE_MFWD6, BOOST_MOVE_MFWD(6)
#define BOOST_MOVE_MFWD8 BOOST_MOVE_MFWD7, BOOST_MOVE_MFWD(7)
#define BOOST_MOVE_MFWD9 BOOST_MOVE_MFWD8, BOOST_MOVE_MFWD(8)

//BOOST_MOVE_MINCN
#define BOOST_MOVE_MINC0
#define BOOST_MOVE_MINC1 BOOST_MOVE_MINC(0)
#define BOOST_MOVE_MINC2 BOOST_MOVE_MINC1, BOOST_MOVE_MINC(1)
#define BOOST_MOVE_MINC3 BOOST_MOVE_MINC2, BOOST_MOVE_MINC(2)
#define BOOST_MOVE_MINC4 BOOST_MOVE_MINC3, BOOST_MOVE_MINC(3)
#define BOOST_MOVE_MINC5 BOOST_MOVE_MINC4, BOOST_MOVE_MINC(4)
#define BOOST_MOVE_MINC6 BOOST_MOVE_MINC5, BOOST_MOVE_MINC(5)
#define BOOST_MOVE_MINC7 BOOST_MOVE_MINC6, BOOST_MOVE_MINC(6)
#define BOOST_MOVE_MINC8 BOOST_MOVE_MINC7, BOOST_MOVE_MINC(7)
#define BOOST_MOVE_MINC9 BOOST_MOVE_MINC8, BOOST_MOVE_MINC(8)

//BOOST_MOVE_MITFWDN
#define BOOST_MOVE_MITFWD0
#define BOOST_MOVE_MITFWD1 BOOST_MOVE_MITFWD(0)
#define BOOST_MOVE_MITFWD2 BOOST_MOVE_MITFWD1, BOOST_MOVE_MITFWD(1)
#define BOOST_MOVE_MITFWD3 BOOST_MOVE_MITFWD2, BOOST_MOVE_MITFWD(2)
#define BOOST_MOVE_MITFWD4 BOOST_MOVE_MITFWD3, BOOST_MOVE_MITFWD(3)
#define BOOST_MOVE_MITFWD5 BOOST_MOVE_MITFWD4, BOOST_MOVE_MITFWD(4)
#define BOOST_MOVE_MITFWD6 BOOST_MOVE_MITFWD5, BOOST_MOVE_MITFWD(5)
#define BOOST_MOVE_MITFWD7 BOOST_MOVE_MITFWD6, BOOST_MOVE_MITFWD(6)
#define BOOST_MOVE_MITFWD8 BOOST_MOVE_MITFWD7, BOOST_MOVE_MITFWD(7)
#define BOOST_MOVE_MITFWD9 BOOST_MOVE_MITFWD8, BOOST_MOVE_MITFWD(8)


//BOOST_MOVE_FWD_INITN
#define BOOST_MOVE_FWD_INIT0
#define BOOST_MOVE_FWD_INIT1 m_p0(::boost::forward<P0>(p0))
#define BOOST_MOVE_FWD_INIT2 BOOST_MOVE_FWD_INIT1, m_p1(::boost::forward<P1>(p1))
#define BOOST_MOVE_FWD_INIT3 BOOST_MOVE_FWD_INIT2, m_p2(::boost::forward<P2>(p2))
#define BOOST_MOVE_FWD_INIT4 BOOST_MOVE_FWD_INIT3, m_p3(::boost::forward<P3>(p3))
#define BOOST_MOVE_FWD_INIT5 BOOST_MOVE_FWD_INIT4, m_p4(::boost::forward<P4>(p4))
#define BOOST_MOVE_FWD_INIT6 BOOST_MOVE_FWD_INIT5, m_p5(::boost::forward<P5>(p5))
#define BOOST_MOVE_FWD_INIT7 BOOST_MOVE_FWD_INIT6, m_p6(::boost::forward<P6>(p6))
#define BOOST_MOVE_FWD_INIT8 BOOST_MOVE_FWD_INIT7, m_p7(::boost::forward<P7>(p7))
#define BOOST_MOVE_FWD_INIT9 BOOST_MOVE_FWD_INIT8, m_p8(::boost::forward<P8>(p8))

//BOOST_MOVE_VAL_INITN
#define BOOST_MOVE_VAL_INIT0
#define BOOST_MOVE_VAL_INIT1 m_p0(p0)
#define BOOST_MOVE_VAL_INIT2 BOOST_MOVE_VAL_INIT1, m_p1(p1)
#define BOOST_MOVE_VAL_INIT3 BOOST_MOVE_VAL_INIT2, m_p2(p2)
#define BOOST_MOVE_VAL_INIT4 BOOST_MOVE_VAL_INIT3, m_p3(p3)
#define BOOST_MOVE_VAL_INIT5 BOOST_MOVE_VAL_INIT4, m_p4(p4)
#define BOOST_MOVE_VAL_INIT6 BOOST_MOVE_VAL_INIT5, m_p5(p5)
#define BOOST_MOVE_VAL_INIT7 BOOST_MOVE_VAL_INIT6, m_p6(p6)
#define BOOST_MOVE_VAL_INIT8 BOOST_MOVE_VAL_INIT7, m_p7(p7)
#define BOOST_MOVE_VAL_INIT9 BOOST_MOVE_VAL_INIT8, m_p8(p8)

//BOOST_MOVE_UREFN
#define BOOST_MOVE_UREF0
#define BOOST_MOVE_UREF1 BOOST_FWD_REF(P0) p0
#define BOOST_MOVE_UREF2 BOOST_MOVE_UREF1, BOOST_FWD_REF(P1) p1
#define BOOST_MOVE_UREF3 BOOST_MOVE_UREF2, BOOST_FWD_REF(P2) p2
#define BOOST_MOVE_UREF4 BOOST_MOVE_UREF3, BOOST_FWD_REF(P3) p3
#define BOOST_MOVE_UREF5 BOOST_MOVE_UREF4, BOOST_FWD_REF(P4) p4
#define BOOST_MOVE_UREF6 BOOST_MOVE_UREF5, BOOST_FWD_REF(P5) p5
#define BOOST_MOVE_UREF7 BOOST_MOVE_UREF6, BOOST_FWD_REF(P6) p6
#define BOOST_MOVE_UREF8 BOOST_MOVE_UREF7, BOOST_FWD_REF(P7) p7
#define BOOST_MOVE_UREF9 BOOST_MOVE_UREF8, BOOST_FWD_REF(P8) p8

//BOOST_MOVE_VALN
#define BOOST_MOVE_VAL0
#define BOOST_MOVE_VAL1 P0 p0
#define BOOST_MOVE_VAL2 BOOST_MOVE_VAL1, BOOST_FWD_REF(P1) p1
#define BOOST_MOVE_VAL3 BOOST_MOVE_VAL2, BOOST_FWD_REF(P2) p2
#define BOOST_MOVE_VAL4 BOOST_MOVE_VAL3, BOOST_FWD_REF(P3) p3
#define BOOST_MOVE_VAL5 BOOST_MOVE_VAL4, BOOST_FWD_REF(P4) p4
#define BOOST_MOVE_VAL6 BOOST_MOVE_VAL5, BOOST_FWD_REF(P5) p5
#define BOOST_MOVE_VAL7 BOOST_MOVE_VAL6, BOOST_FWD_REF(P6) p6
#define BOOST_MOVE_VAL8 BOOST_MOVE_VAL7, BOOST_FWD_REF(P7) p7
#define BOOST_MOVE_VAL9 BOOST_MOVE_VAL8, BOOST_FWD_REF(P8) p8

//BOOST_MOVE_UREFQN
#define BOOST_MOVE_UREFQ0
#define BOOST_MOVE_UREFQ1 BOOST_FWD_REF(Q0) q0
#define BOOST_MOVE_UREFQ2 BOOST_MOVE_UREFQ1, BOOST_FWD_REF(Q1) q1
#define BOOST_MOVE_UREFQ3 BOOST_MOVE_UREFQ2, BOOST_FWD_REF(Q2) q2
#define BOOST_MOVE_UREFQ4 BOOST_MOVE_UREFQ3, BOOST_FWD_REF(Q3) q3
#define BOOST_MOVE_UREFQ5 BOOST_MOVE_UREFQ4, BOOST_FWD_REF(Q4) q4
#define BOOST_MOVE_UREFQ6 BOOST_MOVE_UREFQ5, BOOST_FWD_REF(Q5) q5
#define BOOST_MOVE_UREFQ7 BOOST_MOVE_UREFQ6, BOOST_FWD_REF(Q6) q6
#define BOOST_MOVE_UREFQ8 BOOST_MOVE_UREFQ7, BOOST_FWD_REF(Q7) q7
#define BOOST_MOVE_UREFQ9 BOOST_MOVE_UREFQ8, BOOST_FWD_REF(Q8) q8

//BOOST_MOVE_CREFN
#define BOOST_MOVE_UNVOIDCREF(T) const typename boost::move_detail::unvoid<T>::type&
#define BOOST_MOVE_CREF0
#define BOOST_MOVE_CREF1 BOOST_MOVE_UNVOIDCREF(P0) p0
#define BOOST_MOVE_CREF2 BOOST_MOVE_CREF1, BOOST_MOVE_UNVOIDCREF(P1) p1
#define BOOST_MOVE_CREF3 BOOST_MOVE_CREF2, BOOST_MOVE_UNVOIDCREF(P2) p2
#define BOOST_MOVE_CREF4 BOOST_MOVE_CREF3, BOOST_MOVE_UNVOIDCREF(P3) p3
#define BOOST_MOVE_CREF5 BOOST_MOVE_CREF4, BOOST_MOVE_UNVOIDCREF(P4) p4
#define BOOST_MOVE_CREF6 BOOST_MOVE_CREF5, BOOST_MOVE_UNVOIDCREF(P5) p5
#define BOOST_MOVE_CREF7 BOOST_MOVE_CREF6, BOOST_MOVE_UNVOIDCREF(P6) p6
#define BOOST_MOVE_CREF8 BOOST_MOVE_CREF7, BOOST_MOVE_UNVOIDCREF(P7) p7
#define BOOST_MOVE_CREF9 BOOST_MOVE_CREF8, BOOST_MOVE_UNVOIDCREF(P8) p8

//BOOST_MOVE_CLASSN
#define BOOST_MOVE_CLASS0
#define BOOST_MOVE_CLASS1 class P0
#define BOOST_MOVE_CLASS2 BOOST_MOVE_CLASS1, class P1
#define BOOST_MOVE_CLASS3 BOOST_MOVE_CLASS2, class P2
#define BOOST_MOVE_CLASS4 BOOST_MOVE_CLASS3, class P3
#define BOOST_MOVE_CLASS5 BOOST_MOVE_CLASS4, class P4
#define BOOST_MOVE_CLASS6 BOOST_MOVE_CLASS5, class P5
#define BOOST_MOVE_CLASS7 BOOST_MOVE_CLASS6, class P6
#define BOOST_MOVE_CLASS8 BOOST_MOVE_CLASS7, class P7
#define BOOST_MOVE_CLASS9 BOOST_MOVE_CLASS8, class P8

//BOOST_MOVE_CLASSQN
#define BOOST_MOVE_CLASSQ0
#define BOOST_MOVE_CLASSQ1 class Q0
#define BOOST_MOVE_CLASSQ2 BOOST_MOVE_CLASSQ1, class Q1
#define BOOST_MOVE_CLASSQ3 BOOST_MOVE_CLASSQ2, class Q2
#define BOOST_MOVE_CLASSQ4 BOOST_MOVE_CLASSQ3, class Q3
#define BOOST_MOVE_CLASSQ5 BOOST_MOVE_CLASSQ4, class Q4
#define BOOST_MOVE_CLASSQ6 BOOST_MOVE_CLASSQ5, class Q5
#define BOOST_MOVE_CLASSQ7 BOOST_MOVE_CLASSQ6, class Q6
#define BOOST_MOVE_CLASSQ8 BOOST_MOVE_CLASSQ7, class Q7
#define BOOST_MOVE_CLASSQ9 BOOST_MOVE_CLASSQ8, class Q8

//BOOST_MOVE_CLASSDFLTN
#define BOOST_MOVE_CLASSDFLT0
#define BOOST_MOVE_CLASSDFLT1 class P0 = void
#define BOOST_MOVE_CLASSDFLT2 BOOST_MOVE_CLASSDFLT1, class P1 = void
#define BOOST_MOVE_CLASSDFLT3 BOOST_MOVE_CLASSDFLT2, class P2 = void
#define BOOST_MOVE_CLASSDFLT4 BOOST_MOVE_CLASSDFLT3, class P3 = void
#define BOOST_MOVE_CLASSDFLT5 BOOST_MOVE_CLASSDFLT4, class P4 = void
#define BOOST_MOVE_CLASSDFLT6 BOOST_MOVE_CLASSDFLT5, class P5 = void
#define BOOST_MOVE_CLASSDFLT7 BOOST_MOVE_CLASSDFLT6, class P6 = void
#define BOOST_MOVE_CLASSDFLT8 BOOST_MOVE_CLASSDFLT7, class P7 = void
#define BOOST_MOVE_CLASSDFLT9 BOOST_MOVE_CLASSDFLT8, class P8 = void

//BOOST_MOVE_TARGN
#define BOOST_MOVE_TARG0
#define BOOST_MOVE_TARG1 P0
#define BOOST_MOVE_TARG2 BOOST_MOVE_TARG1, P1
#define BOOST_MOVE_TARG3 BOOST_MOVE_TARG2, P2
#define BOOST_MOVE_TARG4 BOOST_MOVE_TARG3, P3
#define BOOST_MOVE_TARG5 BOOST_MOVE_TARG4, P4
#define BOOST_MOVE_TARG6 BOOST_MOVE_TARG5, P5
#define BOOST_MOVE_TARG7 BOOST_MOVE_TARG6, P6
#define BOOST_MOVE_TARG8 BOOST_MOVE_TARG7, P7
#define BOOST_MOVE_TARG9 BOOST_MOVE_TARG8, P8

//BOOST_MOVE_FWD_TN
#define BOOST_MOVE_FWD_T0
#define BOOST_MOVE_FWD_T1 typename ::boost::move_detail::forward_type<P0>::type
#define BOOST_MOVE_FWD_T2 BOOST_MOVE_FWD_T1, typename ::boost::move_detail::forward_type<P1>::type
#define BOOST_MOVE_FWD_T3 BOOST_MOVE_FWD_T2, typename ::boost::move_detail::forward_type<P2>::type
#define BOOST_MOVE_FWD_T4 BOOST_MOVE_FWD_T3, typename ::boost::move_detail::forward_type<P3>::type
#define BOOST_MOVE_FWD_T5 BOOST_MOVE_FWD_T4, typename ::boost::move_detail::forward_type<P4>::type
#define BOOST_MOVE_FWD_T6 BOOST_MOVE_FWD_T5, typename ::boost::move_detail::forward_type<P5>::type
#define BOOST_MOVE_FWD_T7 BOOST_MOVE_FWD_T6, typename ::boost::move_detail::forward_type<P6>::type
#define BOOST_MOVE_FWD_T8 BOOST_MOVE_FWD_T7, typename ::boost::move_detail::forward_type<P7>::type
#define BOOST_MOVE_FWD_T9 BOOST_MOVE_FWD_T8, typename ::boost::move_detail::forward_type<P8>::type

//BOOST_MOVE_MREFX
#define BOOST_MOVE_MREF0
#define BOOST_MOVE_MREF1 BOOST_MOVE_MREF(P0) m_p0;
#define BOOST_MOVE_MREF2 BOOST_MOVE_MREF1 BOOST_MOVE_MREF(P1) m_p1;
#define BOOST_MOVE_MREF3 BOOST_MOVE_MREF2 BOOST_MOVE_MREF(P2) m_p2;
#define BOOST_MOVE_MREF4 BOOST_MOVE_MREF3 BOOST_MOVE_MREF(P3) m_p3;
#define BOOST_MOVE_MREF5 BOOST_MOVE_MREF4 BOOST_MOVE_MREF(P4) m_p4;
#define BOOST_MOVE_MREF6 BOOST_MOVE_MREF5 BOOST_MOVE_MREF(P5) m_p5;
#define BOOST_MOVE_MREF7 BOOST_MOVE_MREF6 BOOST_MOVE_MREF(P6) m_p6;
#define BOOST_MOVE_MREF8 BOOST_MOVE_MREF7 BOOST_MOVE_MREF(P7) m_p7;
#define BOOST_MOVE_MREF9 BOOST_MOVE_MREF8 BOOST_MOVE_MREF(P8) m_p8;

//BOOST_MOVE_MEMBX
#define BOOST_MOVE_MEMB0
#define BOOST_MOVE_MEMB1 P0 m_p0;
#define BOOST_MOVE_MEMB2 BOOST_MOVE_MEMB1 P1 m_p1;
#define BOOST_MOVE_MEMB3 BOOST_MOVE_MEMB2 P2 m_p2;
#define BOOST_MOVE_MEMB4 BOOST_MOVE_MEMB3 P3 m_p3;
#define BOOST_MOVE_MEMB5 BOOST_MOVE_MEMB4 P4 m_p4;
#define BOOST_MOVE_MEMB6 BOOST_MOVE_MEMB5 P5 m_p5;
#define BOOST_MOVE_MEMB7 BOOST_MOVE_MEMB6 P6 m_p6;
#define BOOST_MOVE_MEMB8 BOOST_MOVE_MEMB7 P7 m_p7;
#define BOOST_MOVE_MEMB9 BOOST_MOVE_MEMB8 P8 m_p8;

//BOOST_MOVE_TMPL_LTN
#define BOOST_MOVE_TMPL_LT0
#define BOOST_MOVE_TMPL_LT1 template<
#define BOOST_MOVE_TMPL_LT2 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT3 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT4 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT5 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT6 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT7 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT8 BOOST_MOVE_TMPL_LT1
#define BOOST_MOVE_TMPL_LT9 BOOST_MOVE_TMPL_LT1

//BOOST_MOVE_LTN
#define BOOST_MOVE_LT0
#define BOOST_MOVE_LT1 <
#define BOOST_MOVE_LT2 BOOST_MOVE_LT1
#define BOOST_MOVE_LT3 BOOST_MOVE_LT1
#define BOOST_MOVE_LT4 BOOST_MOVE_LT1
#define BOOST_MOVE_LT5 BOOST_MOVE_LT1
#define BOOST_MOVE_LT6 BOOST_MOVE_LT1
#define BOOST_MOVE_LT7 BOOST_MOVE_LT1
#define BOOST_MOVE_LT8 BOOST_MOVE_LT1
#define BOOST_MOVE_LT9 BOOST_MOVE_LT1

//BOOST_MOVE_GTN
#define BOOST_MOVE_GT0
#define BOOST_MOVE_GT1 >
#define BOOST_MOVE_GT2 BOOST_MOVE_GT1
#define BOOST_MOVE_GT3 BOOST_MOVE_GT1
#define BOOST_MOVE_GT4 BOOST_MOVE_GT1
#define BOOST_MOVE_GT5 BOOST_MOVE_GT1
#define BOOST_MOVE_GT6 BOOST_MOVE_GT1
#define BOOST_MOVE_GT7 BOOST_MOVE_GT1
#define BOOST_MOVE_GT8 BOOST_MOVE_GT1
#define BOOST_MOVE_GT9 BOOST_MOVE_GT1

//BOOST_MOVE_LPN
#define BOOST_MOVE_LP0
#define BOOST_MOVE_LP1 (
#define BOOST_MOVE_LP2 BOOST_MOVE_LP1
#define BOOST_MOVE_LP3 BOOST_MOVE_LP1
#define BOOST_MOVE_LP4 BOOST_MOVE_LP1
#define BOOST_MOVE_LP5 BOOST_MOVE_LP1
#define BOOST_MOVE_LP6 BOOST_MOVE_LP1
#define BOOST_MOVE_LP7 BOOST_MOVE_LP1
#define BOOST_MOVE_LP8 BOOST_MOVE_LP1
#define BOOST_MOVE_LP9 BOOST_MOVE_LP1

//BOOST_MOVE_RPN
#define BOOST_MOVE_RP0
#define BOOST_MOVE_RP1 )
#define BOOST_MOVE_RP2 BOOST_MOVE_RP1
#define BOOST_MOVE_RP3 BOOST_MOVE_RP1
#define BOOST_MOVE_RP4 BOOST_MOVE_RP1
#define BOOST_MOVE_RP5 BOOST_MOVE_RP1
#define BOOST_MOVE_RP6 BOOST_MOVE_RP1
#define BOOST_MOVE_RP7 BOOST_MOVE_RP1
#define BOOST_MOVE_RP8 BOOST_MOVE_RP1
#define BOOST_MOVE_RP9 BOOST_MOVE_RP1

//BOOST_MOVE_IN
#define BOOST_MOVE_I0
#define BOOST_MOVE_I1 ,
#define BOOST_MOVE_I2 BOOST_MOVE_I1
#define BOOST_MOVE_I3 BOOST_MOVE_I1
#define BOOST_MOVE_I4 BOOST_MOVE_I1
#define BOOST_MOVE_I5 BOOST_MOVE_I1
#define BOOST_MOVE_I6 BOOST_MOVE_I1
#define BOOST_MOVE_I7 BOOST_MOVE_I1
#define BOOST_MOVE_I8 BOOST_MOVE_I1
#define BOOST_MOVE_I9 BOOST_MOVE_I1

//BOOST_MOVE_COLON
#define BOOST_MOVE_COLON0
#define BOOST_MOVE_COLON1 :
#define BOOST_MOVE_COLON2 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON3 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON4 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON5 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON6 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON7 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON8 BOOST_MOVE_COLON1
#define BOOST_MOVE_COLON9 BOOST_MOVE_COLON1

//BOOST_MOVE_ITERATE_2TON
#define BOOST_MOVE_ITERATE_2TO2(MACROFUNC)   MACROFUNC(2)
#define BOOST_MOVE_ITERATE_2TO3(MACROFUNC)   BOOST_MOVE_ITERATE_2TO2(MACROFUNC)  MACROFUNC(3)
#define BOOST_MOVE_ITERATE_2TO4(MACROFUNC)   BOOST_MOVE_ITERATE_2TO3(MACROFUNC)  MACROFUNC(4)
#define BOOST_MOVE_ITERATE_2TO5(MACROFUNC)   BOOST_MOVE_ITERATE_2TO4(MACROFUNC)  MACROFUNC(5)
#define BOOST_MOVE_ITERATE_2TO6(MACROFUNC)   BOOST_MOVE_ITERATE_2TO5(MACROFUNC)  MACROFUNC(6)
#define BOOST_MOVE_ITERATE_2TO7(MACROFUNC)   BOOST_MOVE_ITERATE_2TO6(MACROFUNC)  MACROFUNC(7)
#define BOOST_MOVE_ITERATE_2TO8(MACROFUNC)   BOOST_MOVE_ITERATE_2TO7(MACROFUNC)  MACROFUNC(8)
#define BOOST_MOVE_ITERATE_2TO9(MACROFUNC)   BOOST_MOVE_ITERATE_2TO8(MACROFUNC)  MACROFUNC(9)

//BOOST_MOVE_ITERATE_1TON
#define BOOST_MOVE_ITERATE_1TO1(MACROFUNC)   MACROFUNC(1)
#define BOOST_MOVE_ITERATE_1TO2(MACROFUNC)   BOOST_MOVE_ITERATE_1TO1(MACROFUNC)  MACROFUNC(2)
#define BOOST_MOVE_ITERATE_1TO3(MACROFUNC)   BOOST_MOVE_ITERATE_1TO2(MACROFUNC)  MACROFUNC(3)
#define BOOST_MOVE_ITERATE_1TO4(MACROFUNC)   BOOST_MOVE_ITERATE_1TO3(MACROFUNC)  MACROFUNC(4)
#define BOOST_MOVE_ITERATE_1TO5(MACROFUNC)   BOOST_MOVE_ITERATE_1TO4(MACROFUNC)  MACROFUNC(5)
#define BOOST_MOVE_ITERATE_1TO6(MACROFUNC)   BOOST_MOVE_ITERATE_1TO5(MACROFUNC)  MACROFUNC(6)
#define BOOST_MOVE_ITERATE_1TO7(MACROFUNC)   BOOST_MOVE_ITERATE_1TO6(MACROFUNC)  MACROFUNC(7)
#define BOOST_MOVE_ITERATE_1TO8(MACROFUNC)   BOOST_MOVE_ITERATE_1TO7(MACROFUNC)  MACROFUNC(8)
#define BOOST_MOVE_ITERATE_1TO9(MACROFUNC)   BOOST_MOVE_ITERATE_1TO8(MACROFUNC)  MACROFUNC(9)

//BOOST_MOVE_ITERATE_0TON
#define BOOST_MOVE_ITERATE_0TO0(MACROFUNC)   MACROFUNC(0)
#define BOOST_MOVE_ITERATE_0TO1(MACROFUNC)   BOOST_MOVE_ITERATE_0TO0(MACROFUNC)  MACROFUNC(1)
#define BOOST_MOVE_ITERATE_0TO2(MACROFUNC)   BOOST_MOVE_ITERATE_0TO1(MACROFUNC)  MACROFUNC(2)
#define BOOST_MOVE_ITERATE_0TO3(MACROFUNC)   BOOST_MOVE_ITERATE_0TO2(MACROFUNC)  MACROFUNC(3)
#define BOOST_MOVE_ITERATE_0TO4(MACROFUNC)   BOOST_MOVE_ITERATE_0TO3(MACROFUNC)  MACROFUNC(4)
#define BOOST_MOVE_ITERATE_0TO5(MACROFUNC)   BOOST_MOVE_ITERATE_0TO4(MACROFUNC)  MACROFUNC(5)
#define BOOST_MOVE_ITERATE_0TO6(MACROFUNC)   BOOST_MOVE_ITERATE_0TO5(MACROFUNC)  MACROFUNC(6)
#define BOOST_MOVE_ITERATE_0TO7(MACROFUNC)   BOOST_MOVE_ITERATE_0TO6(MACROFUNC)  MACROFUNC(7)
#define BOOST_MOVE_ITERATE_0TO8(MACROFUNC)   BOOST_MOVE_ITERATE_0TO7(MACROFUNC)  MACROFUNC(8)
#define BOOST_MOVE_ITERATE_0TO9(MACROFUNC)   BOOST_MOVE_ITERATE_0TO8(MACROFUNC)  MACROFUNC(9)

//BOOST_MOVE_ITERATE_NTON
#define BOOST_MOVE_ITERATE_0TO0(MACROFUNC)   MACROFUNC(0)
#define BOOST_MOVE_ITERATE_1TO1(MACROFUNC)   MACROFUNC(1)
#define BOOST_MOVE_ITERATE_2TO2(MACROFUNC)   MACROFUNC(2)
#define BOOST_MOVE_ITERATE_3TO3(MACROFUNC)   MACROFUNC(3)
#define BOOST_MOVE_ITERATE_4TO4(MACROFUNC)   MACROFUNC(4)
#define BOOST_MOVE_ITERATE_5TO5(MACROFUNC)   MACROFUNC(5)
#define BOOST_MOVE_ITERATE_6TO6(MACROFUNC)   MACROFUNC(6)
#define BOOST_MOVE_ITERATE_7TO7(MACROFUNC)   MACROFUNC(7)
#define BOOST_MOVE_ITERATE_8TO8(MACROFUNC)   MACROFUNC(8)
#define BOOST_MOVE_ITERATE_9TO9(MACROFUNC)   MACROFUNC(9)

//BOOST_MOVE_CAT
#define BOOST_MOVE_CAT(a, b) BOOST_MOVE_CAT_I(a, b)
#define BOOST_MOVE_CAT_I(a, b) a ## b
//#    define BOOST_MOVE_CAT_I(a, b) BOOST_MOVE_CAT_II(~, a ## b)
//#    define BOOST_MOVE_CAT_II(p, res) res

#endif //#ifndef BOOST_MOVE_DETAIL_FWD_MACROS_HPP
