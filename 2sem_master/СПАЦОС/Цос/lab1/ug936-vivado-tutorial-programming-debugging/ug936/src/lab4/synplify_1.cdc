# Attributes that are needed to mark_debug the nets that are needed to be viewed in ILA

define_attribute  -comment {Mark sinegen as black box} {v:work.sinegen} {syn_black_box} {1}
define_attribute  -comment {Set no_prune on sinegen} {v:work.sinegen} {syn_noprune} {1}
define_attribute  -comment {Mark entire bus for debug} {i:sinegen.sine[*]} {mark_debug} {"true"}
define_attribute  -comment {Mark entire bus for debug} {i:sinegen.sel[*]} {mark_debug} {"true"}
