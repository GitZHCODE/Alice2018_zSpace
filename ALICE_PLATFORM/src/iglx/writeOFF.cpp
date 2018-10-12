// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "writeOFF.h"
#include <cstdio>

// write mesh to an ascii off file
template <typename DerivedV, typename DerivedF>
IGL_INLINE bool igl::writeOFF(
  const std::string fname,
  const Eigen::PlainObjectBase<DerivedV>& V,
  const Eigen::PlainObjectBase<DerivedF>& F)
{
  FILE *fp = fopen (fname.c_str(), "w");


  if (!fp)
  {
      fprintf (stderr, "writeOFF(): could not open file %s", fname.c_str());
    return false;
  }

  fprintf (fp, "OFF\n%d %d 0\n",  (int) V.rows(), (int) F.rows());

  for (int i = 0; i < V.rows(); i++)
  {
    fprintf(
      fp,
      "%0.17g %0.17g %0.17g\n",
      (double)V(i,0),
      (double)V(i,1),
      (double)V(i,2));
  }

//  for (int i = 0; i < F.rows(); i++)
//      fprintf (fp, "3 %d %d %d\n", F(i,0), F(i,1), F(i,2));
  for (int i = 0; i < (int)F.rows(); i++)
  {
    fprintf (fp, "%d", (int)F.cols());
    for (int j = 0; j < (int)F.cols(); j++)
      fprintf (fp, " %d", (int)F(i,j));
    fprintf (fp, "\n");
  }
  fclose (fp);
  return true;
}
#ifdef IGL_STATIC_LIBRARY
// Explicit template specialization
// generated by autoexplicit.sh
template bool igl::writeOFF<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&);
template bool igl::writeOFF<Eigen::Matrix<double, -1, 3, 1, -1, 3>, Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1> > const&);
template bool igl::writeOFF<Eigen::Matrix<float, -1, 3, 1, -1, 3>, Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1> > const&);
template bool igl::writeOFF<Eigen::Matrix<double, -1, 3, 0, -1, 3>, Eigen::Matrix<int, -1, 3, 0, -1, 3> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&);
template bool igl::writeOFF<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, 3, 0, -1, 3> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&);
#endif
