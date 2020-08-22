// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_CONDITION_HPP
#define XVEGA_ENCODING_OPTIONS_CONDITION_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./timeunit.hpp"
#include "./datetime.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_object_type = xtl::variant<nl::json, std::string>;
    using field_predicate_equal_type = xtl::variant<std::string, double, int, bool, DateTime>;
    using field_predicate_type = xtl::variant<std::string, double, int, DateTime>;
    using field_predicate_range_type = xtl::variant<
                                            std::vector<double>, 
                                            std::vector<int>, 
                                            std::vector<DateTime>, 
                                            std::vector<std::nullptr_t>
                                            >;
    using any_array_type = xtl::variant<
                                std::vector<std::string>, 
                                std::vector<double>, 
                                std::vector<int>, 
                                std::vector<bool>, 
                                std::vector<DateTime>
                                >;

    struct FieldPredicate : public xp::xobserved<FieldPredicate>
    {
        XPROPERTY(xtl::xoptional<std::string>, FieldPredicate, field);
        XPROPERTY(xtl::xoptional<TimeUnit>, FieldPredicate, timeUnit);
        XPROPERTY(xtl::xoptional<field_predicate_equal_type>, FieldPredicate, equal);
        XPROPERTY(xtl::xoptional<field_predicate_type>, FieldPredicate, lt);
        XPROPERTY(xtl::xoptional<field_predicate_type>, FieldPredicate, lte);
        XPROPERTY(xtl::xoptional<field_predicate_type>, FieldPredicate, gt);
        XPROPERTY(xtl::xoptional<field_predicate_type>, FieldPredicate, gte);
        XPROPERTY(xtl::xoptional<field_predicate_range_type>, FieldPredicate, range);
        XPROPERTY(xtl::xoptional<any_array_type>, FieldPredicate, oneOf);
        XPROPERTY(xtl::xoptional<bool>, FieldPredicate, valid);
    };

    void to_json(nl::json& j, const FieldPredicate& data)
    {
        serialize(j, data.field(), "field");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.equal(), "equal");
        serialize(j, data.lt(), "lt");
        serialize(j, data.lte(), "lte");
        serialize(j, data.gt(), "gt");
        serialize(j, data.gte(), "gte");
        serialize(j, data.range(), "range");
        serialize(j, data.oneOf(), "oneOf");
        serialize(j, data.valid(), "valid");
    }

    struct SelectionPredicate : public xp::xobserved<SelectionPredicate>
    {
        XPROPERTY(xtl::xoptional<string_object_type>, SelectionPredicate, selection);
    };

    void to_json(nl::json& j, const SelectionPredicate& data)
    {
        serialize(j, data.selection(), "selection");
    }

    using predicate_type = xtl::variant<std::string, FieldPredicate, SelectionPredicate>;
}

#endif