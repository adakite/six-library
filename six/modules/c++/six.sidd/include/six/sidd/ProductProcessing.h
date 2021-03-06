/* =========================================================================
 * This file is part of six.sidd-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * six.sidd-c++ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef __SIX_PRODUCT_PROCESSING_H__
#define __SIX_PRODUCT_PROCESSING_H__

#include "six/Types.h"
#include "six/Init.h"
#include "six/ParameterCollection.h"

namespace six
{
namespace sidd
{
/*!
 *  \struct ProcessingModule
 *  \brief SIDD ProcessingModule
 *
 *  Processing module to keep track of the name and 
 *  any parameters associated with the algorithms used
 *  to produce the SIDD.  Note that moduleParameters and
 *  processingModules are mutually exclusive.
 *
 */
struct ProcessingModule
{
    //!  The name of the module
    Parameter moduleName;

    /*! 
     *  Parameters associated with the algorithm used in
     *  processing the product.
     */
    ParameterCollection moduleParameters;

    /*!
     *  ProcessingModule is a repeatabl structure within
     *  itself to create an algorithm as a subset of another
     *  algorithm
     *
     */
    std::vector<mem::ScopedCloneablePtr<ProcessingModule> > processingModules;

    //!  Clone
    ProcessingModule* clone() const;

    //! Equality operator
    bool operator==(const ProcessingModule& rhs) const
    {
        return (moduleName == rhs.moduleName && moduleParameters == rhs.moduleParameters &&
            processingModules == rhs.processingModules);
    }

    bool operator!=(const ProcessingModule& rhs) const
    {
        return !(*this == rhs);
    }
};

/*!
 *  \struct ProductProcessing
 *  \brief SIDD ProductProcessing parameters
 *
 *  (Optional) Contains metadata related to algorithms 
 *  used during product generation.
 */
struct ProductProcessing
{
    //!  Clone
    ProductProcessing* clone() const;

    //!  Contains only a set of ProcessingModule components
    std::vector<mem::ScopedCloneablePtr<ProcessingModule> > processingModules;

    //! Equality operator
    bool operator==(const ProductProcessing& rhs) const
    {
        return processingModules == rhs.processingModules;
    }

    bool operator!=(const ProductProcessing& rhs) const
    {
        return !(*this == rhs);
    }
};

}
}
#endif

