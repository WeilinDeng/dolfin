// Copyright (C) 2012 Anders Logg, Benjamin Kehlet, Johannes Ring
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
// First added:  2012-01-01
// Last changed: 2012-05-10


#include <dolfin/log/log.h>
#include "CSGMeshGenerator.h"
#include "CSGGeometry.h"
#include "CSGCGALMeshGenerator2D.h"
#include "CSGCGALMeshGenerator3D.h"

using namespace dolfin;

#ifdef HAS_CGAL

//-----------------------------------------------------------------------------
void CSGMeshGenerator::generate(Mesh& mesh,
                                const CSGGeometry& geometry)
{
  if (geometry.dim() == 2)
  {
    CSGCGALMeshGenerator2D generator(geometry);
    generator.generate(mesh);
  }
  else if (geometry.dim() == 3)
  {
    CSGCGALMeshGenerator3D generator(geometry);
    generator.generate(mesh);
  }
  else
  {
    dolfin_error("CSGMeshGenerator.cpp",
                 "create mesh from CSG geometry",
                 "Unhandled geometry dimension %d", geometry.dim());
  }
}
//-----------------------------------------------------------------------------
#else
void CSGMeshGenerator::generate(Mesh& mesh,
                                const CSGGeometry& geometry)
{
  dolfin_error("CSGMeshGenerator.cpp",
	       "create mesh from CSG geometry",
	       "Mesh generation not available. Dolfin has been compiled without CGAL.");
}
#endif
