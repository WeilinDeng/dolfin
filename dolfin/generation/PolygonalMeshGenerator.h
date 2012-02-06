// Copyright (C) 2012 Garth N. Wells
//
// This file is part of DOLFIN.
//
// DOLFIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DOLFIN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with DOLFIN. If not, see <http://www.gnu.org/licenses/>.
//
// First added:  2012-01-05
// Last changed:

#ifndef __DOLFIN_POLYGONALMESHGENERATOR_H
#define __DOLFIN_POLYGONALMESHGENERATOR_H

#ifdef HAS_CGAL

#include <vector>

namespace dolfin
{

  class Mesh;

  /// Polygonal mesh generator that uses CGAL

  class PolygonalMeshGenerator
  {
  public:

    /// Generate mesh of a polygonal domain described by domain vertices
    static void generate(Mesh& mesh, const std::vector<Point>& vertices,
                         double cell_size);

  private:

  };

}

#endif
#endif