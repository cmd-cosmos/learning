# pylint: skip-file
# type: ignore

import streamlit as st

st.title("User Registration")

st.text_input(label="ID", placeholder="enter user id")
st.text_input(label="Name", placeholder="enter user name")

if st.button("Register"):
    st.success("user registered")