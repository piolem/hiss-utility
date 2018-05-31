// --------------------------------------------------------------------------------------------
//
//  Created by Piotr Lemański on 31.05.2018.
//
//  This file is a part of HISS Engine
//  May act as a standalone header-only library.
//
//  Utility provides convenient wrappers of commonly used
//  methods of processing data structures with std algorithm
//  library.
//
//  For more detailed description, please read comments
//  for specific functions implemented below.
//
//  Copyright 2018 Piotr Lemański
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      [http://www.apache.org/licenses/LICENSE-2.0]
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
// --------------------------------------------------------------------------------------------

#pragma once

#include <algorithm>

namespace hi
{
//
// Remove and Erase If
//
// Collects two commonly used function calls regarding
// removal of container contents.
//
// @param Container
//     Standard iterable container.
//
// @param Pred
//     Unary predicate describing the condition of removal.
//
template< class Container, class Predicate >
void remove_erase_if( Container& container, Predicate predicate )
{
    const auto new_end_it = std::remove_if( container.begin(), container.end(), predicate );
    container.erase( new_end_it, container.end() );
};

//
// Unique Full
//
// Performs sorting operation on a container
// and removes consecutive duplicates.
//
// @param Container
//     Standard iterable container.
//
template< class Container >
void unique_full( Container& container )
{
    std::sort( container.begin(), container.end() );
    const auto new_end_it = std::unique( container.begin(), container.end() );
    container.erase( new_end_it, container.end() );
}

} // namespace hi
