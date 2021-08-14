import * as React from 'react'
import Demo from './tree'
import {CodeView} from "../../components/codeview/codeview";

// @ts-ignore
const code = require('!!raw-loader!./tree')

export default () => {
    return (
        <div>
            <Demo/>
            <CodeView code={code}/>
        </div>
    )
}
