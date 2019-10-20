# Automatically generated by pb2py
# fmt: off
import protobuf as p

if __debug__:
    try:
        from typing import Dict, List, Optional
        from typing_extensions import Literal  # noqa: F401
    except ImportError:
        Dict, List, Optional = None, None, None  # type: ignore


class TezosProposalOp(p.MessageType):

    def __init__(
        self,
        source: bytes = None,
        period: int = None,
        proposals: List[bytes] = None,
    ) -> None:
        self.source = source
        self.period = period
        self.proposals = proposals if proposals is not None else []

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('source', p.BytesType, 0),
            2: ('period', p.UVarintType, 0),
            4: ('proposals', p.BytesType, p.FLAG_REPEATED),
        }
