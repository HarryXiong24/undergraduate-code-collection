import * as React from 'react'
import Demo from './datepicker'
import {CodeView} from "../../components/codeview/codeview";

// @ts-ignore
const code = require('!!raw-loader!./datepicker')

export default () => {
    return (
        <div>
            <Demo/>
            <CodeView code={code}/>
        </div>
    )
}
