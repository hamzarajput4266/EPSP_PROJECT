import { useState } from "react";
import firebase from "../firebase";
import "./SendData.css"

function SendData() {
    const [phase1_current, setphase1_current] = useState(0);
    const [phase2_current, setphase2_current] = useState(0);
    const [phase3_current, setphase3_current] = useState(0);
    const [phase1_current_angle, setphase1_current_angle] = useState(0);
    const [phase2_current_angle, setphase2_current_angle] = useState(0);
    const [phase3_current_angle, setphase3_current_angle] = useState(0);
    const [phase1_voltage, setphase1_voltage] = useState(0);
    const [phase2_voltage, setphase2_voltage] = useState(0);
    const [phase3_voltage, setphase3_voltage] = useState(0);
    const [phase1_voltage_angle, setphase1_voltage_angle] = useState(0);
    const [phase2_voltage_angle, setphase2_voltage_angle] = useState(0);
    const [phase3_voltage_angle, setphase3_voltage_angle] = useState(0);
    const [zero_seq, setzero_seq] = useState(0);
    const [positive_seq, setpositive_seq] = useState(0);
    const [negative_seq, setnegative_seq] = useState(0);
    const [Fault_type, setFault_type] = useState(0);


  const sendData =  () => {
    const sendDataRef = firebase.database().ref('test/Input');
    const data = {
      // int: Number(int),
      // float: Number(float)
      phase1_current: Number(phase1_current),
      phase2_current: Number(phase2_current),
      phase3_current: Number(phase3_current),
      phase1_current_angle: Number(phase1_current_angle),
      phase2_current_angle: Number(phase2_current_angle),
      phase3_current_angle: Number(phase3_current_angle),
      phase1_voltage: Number(phase1_voltage),
      phase2_voltage: Number(phase2_voltage),
      phase3_voltage: Number(phase3_voltage),
      phase1_voltage_angle: Number(phase1_voltage_angle),
      phase2_voltage_angle: Number(phase2_voltage_angle),
      phase3_voltage_angle: Number(phase3_voltage_angle),
      zero_seq:Number(zero_seq),
      positive_seq:Number(positive_seq),
      negative_seq:Number(negative_seq),
      Fault_type: String(Fault_type),
      
      



    };

    sendDataRef.set(data);
  };
    return (
        <div className="gpt3__header section__padding">
          {/* <div className="gpt3__header-content"> */}
          <div className="gpt3__header-content">
            <h1>DATA FOR EPSP</h1>

            <h2>Sending Data to Firebase</h2>
          
            <h3>Enter Phase1 current Magnitude  </h3>
            <input type="number" value={phase1_current} onChange={(e)=>setphase1_current(e.target.value)} placeholder="Enter Int Value" />

            <h3>Enter Phase2 current Magnitude </h3>
            <input type="number" value={phase2_current} onChange={(e)=>setphase2_current(e.target.value)} placeholder="Enter Float Value"/>
            <h3>Enter Phase3 current Magnitude  </h3>
            <input type="number" value={phase3_current} onChange={(e)=>setphase3_current(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase1 current Angle </h3>
            <input type="number" value={phase1_current_angle} onChange={(e)=>setphase1_current_angle(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase2 current Angle  </h3>
            <input type="number" value={phase2_current_angle} onChange={(e)=>setphase2_current_angle(e.target.value)} placeholder="Enter Int Value" />
            
            <h3>Enter Phase3 current Angle </h3>
            <input type="number" value={phase3_current_angle} onChange={(e)=>setphase3_current_angle(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase1 voltage Magnitude  </h3>
            <input type="number" value={phase1_voltage} onChange={(e)=>setphase1_voltage(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase2 voltage Magnitude  </h3>
            <input type="number" value={phase2_voltage} onChange={(e)=>setphase2_voltage(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase3 voltage Magnitude  </h3>
            <input type="number" value={phase3_voltage} onChange={(e)=>setphase3_voltage(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase1 voltage Angle  </h3>
            <input type="number" value={phase1_voltage_angle} onChange={(e)=>setphase1_voltage_angle(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase2 Voltage Angle  </h3>
            <input type="number" value={phase2_voltage_angle} onChange={(e)=>setphase2_voltage_angle(e.target.value)} placeholder="Enter Int Value" />
            <h3>Enter Phase3 Voltage Angle  </h3>
            <input type="number" value={phase3_voltage_angle} onChange={(e)=>setphase3_voltage_angle(e.target.value)} placeholder="Enter Int Value" />
            <div className="gpt3__header-content__input">
            
            <button onClick={sendData}>Send Data</button>
            </div>
          </div>
         </div>
      
    )
}

export default SendData
