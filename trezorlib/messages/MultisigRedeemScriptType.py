# Automatically generated by pb2py
from __future__ import absolute_import
from .. import protobuf as p
from .HDNodePathType import HDNodePathType


class MultisigRedeemScriptType(p.MessageType):
    FIELDS = {
        1: ('pubkeys', HDNodePathType, p.FLAG_REPEATED),
        2: ('signatures', p.BytesType, p.FLAG_REPEATED),
        3: ('m', p.UVarintType, 0),
    }