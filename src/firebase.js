import firebase from 'firebase';

const firebaseConfig = {
  apiKey: "AIzaSyBHtgxSVQwP-_OJv0cfj1a525ssrBBEVLM",
  authDomain: "epsp-cep-2022.firebaseapp.com",
  databaseURL: "https://epsp-cep-2022-default-rtdb.firebaseio.com",
  projectId: "epsp-cep-2022",
  storageBucket: "epsp-cep-2022.appspot.com",
  messagingSenderId: "87275222497",
  appId: "1:87275222497:web:899675930092d618e0cea0",
  measurementId: "G-NHWVZLBLCP"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);

export default firebase;