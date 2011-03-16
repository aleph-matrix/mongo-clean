/**
 * Copyright 2011 10gen Inc.
 *
 * This program is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pch.h"
#include "FieldIterator.h"

#include "Document.h"

namespace mongo
{
    FieldIterator::FieldIterator(shared_ptr<Document> pTheDocument):
	pDocument(pTheDocument),
	index(0)
    {
    }

    bool FieldIterator::more() const
    {
	return (index < pDocument->vFieldName.size());
    }

    pair<string, shared_ptr<const Value>> FieldIterator::next()
    {
	assert(more());
	pair<string, shared_ptr<const Value>> result(
	    pDocument->vFieldName[index], pDocument->vpValue[index]);
	++index;
	return result;
    }
}
