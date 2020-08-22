// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/legend.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

#include "../../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct FillOpacity : public xp::xobserved<FillOpacity>
    {
        XPROPERTY(xtl::xoptional<agg_type>, FillOpacity, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, FillOpacity, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, FillOpacity, condition);
        XPROPERTY(xtl::xoptional<field_type>, FillOpacity, field);
        XPROPERTY(xtl::xoptional<legend_type>, FillOpacity, legend);
        XPROPERTY(xtl::xoptional<scale_type>, FillOpacity, scale);
        XPROPERTY(xtl::xoptional<sort_type>, FillOpacity, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, FillOpacity, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, FillOpacity, title);
        XPROPERTY(xtl::xoptional<std::string>, FillOpacity, type);
    };

    void to_json(nl::json& j, const FillOpacity& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.bin(), "bin");
        // serialize(j, data.condition(), "condition");
        serialize(j, data.field(), "field");
        serialize(j, data.legend(), "legend");
        serialize(j, data.scale(), "scale");
        serialize(j, data.sort(), "sort");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}