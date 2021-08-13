<template>
  <div>
    <p>ID: {{$route.params.id}}</p>
    <ul>
      <li>id: {{message.id}}</li>
      <li>title: {{message.title}}</li>
      <li>content: {{message.content}}</li>
    </ul>
  </div>
</template>

<script>
export default {
  props: {
    message: Object
  }
}
</script>

<style>

</style>
