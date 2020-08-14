{% if q.Status == "Validations" %}
    <tr class="table__row" bgcolor="#fbecec">
{% elif  q.Status == "Edited" %}
    <tr class="table__row" bgcolor="#eff0f9">
{% else %}
    <tr class="table__row">
{% endif %}

    <td class="table__cell ">
        {{ q.Number }}
    </td>
    <td class="table__cell ">
        {{ q.Question }}
    </td>
    <td class="table__cell table__cell--numeric">
        <!-- {% set charLimit = 100 %}
        {% if q.Response | length > charLimit %}
        <input value={{ q.Response.slice(0, charLimit) }} type="text" class="input input--text input-type__input input--w-10">
             {{ q.Response.slice(0, charLimit) }}... [View for more] 
        {% else %} -->
        <input value={{q.Response}} type="text" class="input input--text input-type__input input--w-100">

        <!-- {% endif %} -->
    </td>

    <td class="table__cell ">
        {% if q.Status == "Edited" %}
            <!-- <span class='status status--info'>{{ q.Status }}</span> -->

            <table>
                <tbody>
                    <tr>
                        <td>
                            <span class='status status--info'>This has changed since the last submission</span>
                        </td>
                        <td>
                            <span class="checkbox js-password-toggle-wrap checkbox--toggle u-mt-no u-mb-s">
                                <input type="checkbox" id="{{output['validationoutputid']}}" class="checkbox__input js-checkbox js-password-toggle to-u-bg-w " name="override-checkbox">
                                <label id="label-{{output['validationoutputid']}}" class="checkbox__label to-u-bg " for="{{output['validationoutputid']}}">Override <span class="u-vh">  </span></label>
                            </span>      
                        </td>
                    </tr>
                </tbody>
            </table>
        {% endif %}

        {% if q.Status == "Validations" %}

            <table>
            
            <tbody>
                    
            {% for v in q.ValidationWarnings %}
            <tr>
                <td>
                    <span class='status status--error to-validation'>Warning - {{ v }}</span>
                </td>
                <td>
                {% if q.Severity == "Warning" %}
                    <span class="checkbox js-password-toggle-wrap checkbox--toggle u-mt-no u-mb-s">
                        <input type="checkbox" id="{{output['validationoutputid']}}" class="checkbox__input js-checkbox js-password-toggle to-u-bg-w " name="override-checkbox">
                        <label id="label-{{output['validationoutputid']}}" class="checkbox__label to-u-bg " for="{{output['validationoutputid']}}">Override <span class="u-vh"> {{ output["validationmessage"] | lower }} </span></label>
                    </span>      
                {% endif %}          
                </td>

            </tr>
             {% endfor %}
             {% for v in q.ValidationErrors %}
            <tr>
                <td>
                    <span class='status status--error to-validation'>Error - {{ v }}</span>
                </td>
                <td>         
                </td>

            </tr>
             {% endfor %}

                </tbody>

             </table>

        {% endif %}
    </td class="table__cell ">

    <td class="table__cell ">
        <a href="/prototypes/take-on-1/v3/view-form-rsi.html" role="button" class="btn btn--secondary btn--small"><span class="btn__inner">View</span></a>
    </td>

</tr>
