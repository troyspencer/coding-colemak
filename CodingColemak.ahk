; Colemak with some QOL for coding
; \ and Backspace swapped
; Capslock is now Ctrl
; Ctrl is now Alt
; Alt triggers arrow clusters on ESDF and IJKL 

#SingleInstance force
#NoEnv ; Recommended for performance and compatibility with future AutoHotkey releases.
SendMode Input ; Recommended for new scripts due to its superior speed and reliability.
SetTitleMatchMode 3  ; Exact matching to avoid confusing T/B with Tab/Backspace.

;`::`
;1::1
;2::2
;3::3
;4::4
;5::5
;6::6
;7::7
;8::8
;9::9
;0::0
;-::-
;=::=

;q::q
;w::w
e::f
r::p
t::g
y::j
u::l
i::u
o::y
p::`;
;[::[
;]::]
;\::\

;a::a
s::r
d::s
f::t
g::d
;h::h
j::n
k::e
l::i
`;::o
;'::'

;z::z
;x::x
;c::c
;v::v
;b::b
n::k
;m::m
;,::,
;.::.
;/::/

\::Backspace
Backspace::\
CapsLock::Ctrl
Ctrl::Alt

!e::Send {Up}
!s::Send {Left}
!d::Send {Down}
!f::Send {Right}

!i::Send {Up}
!j::Send {Left}
!k::Send {Down}
!l::Send {Right}