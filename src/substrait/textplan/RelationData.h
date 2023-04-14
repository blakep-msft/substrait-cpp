/* SPDX-License-Identifier: Apache-2.0 */

#pragma once

#include "substrait/proto/algebra.pb.h"

namespace io::substrait::textplan {

struct RelationData {
  RelationData(
      const ::substrait::proto::Rel* relation,
      const ::google::protobuf::Message* origin)
      : protoAddr(relation), originProtoAddr(origin) {
    continuingPipeline = nullptr;
  };

  // The protobuf data relating to this symbol.
  const ::substrait::proto::Rel* protoAddr;

  // The node that directly contains this symbol.
  const ::google::protobuf::Message* originProtoAddr;

  // continuingPipeline is the next step in a pipeline that this symbol is part
  // of.
  const ::substrait::proto::Rel* continuingPipeline;

  // A list of pipelines that start with this node and continue onward.
  std::vector<const ::substrait::proto::Rel*> newPipelines;

  // Column name for each field known to this relation (in field order).
  // TODO -- Use symbols instead of column names here.
  std::vector<std::string> fieldReferences;
};

} // namespace io::substrait::textplan