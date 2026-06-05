#type: ignore
#pylint: skip-file
import streamlit as st

st.title("Echo Bot")

if "messages" not in st.session_state:
    st.session_state.messages = []

for message in st.session_state.messages:
    with st.chat_message(message["role"]):
        st.markdown(message["content"])
    
user_inp = st.chat_input("Enter Query...")

if user_inp:
    st.session_state.messages.append({
        "role" : "user",
        "content" : user_inp
    })
    with st.chat_message("user"):
        st.markdown(user_inp)

    bot_response = f"[ECHO] {user_inp}"
    st.session_state.messages.append(
            {
                "role" : "assistant",
                "content" : bot_response
            }
        )
    with st.chat_message("assistant"):
        st.markdown(bot_response)
