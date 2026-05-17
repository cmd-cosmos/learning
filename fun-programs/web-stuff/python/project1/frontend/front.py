# pylint: skip-file
# type: ignore

import streamlit as st

st.title("User Registration")

if "uid" not in st.session_state:
    st.session_state.uid = ""

if "uname" not in st.session_state:
    st.session_state.uname = ""

with st.form("registration_form"):
    st.text_input(label="ID", placeholder="enter user id", key="uid")
    st.text_input(label="Name", placeholder="enter user name", key="uname")

    submitted = st.form_submit_button("Register")

if submitted:
    st.success("user registered")
    st.session_state.uid = ""
    st.session_state.uname = ""