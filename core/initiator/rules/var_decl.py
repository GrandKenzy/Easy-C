import gram
from core.initiator.rules.value import EC_VALUE


class EC_VAR_DECL(gram.RuleItem):
    name = 'var declaration'
    code = 100000
    grammar = gram.Seq(
        gram.MatchGroup ('types'),
        gram.MatchToken ('IDENT'),
        #  opcionales
         gram.Opt(
            gram.Seq(

                gram.MatchToken ('ASSIGN'),
                gram.Ref (EC_VALUE)
            )
     ),
        gram.Opt(
            gram.MatchToken ('COMMENT')
        )
    )